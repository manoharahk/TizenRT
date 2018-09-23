/******************************************************************
 *
 * Copyright 2018 Samsung Electronics All Rights Reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 ******************************************************************/
#include <pthread.h>
#include <tizenrt/audio/audio.h>
#include <sys/types.h>
#include <debug.h>
#include <unistd.h>

#include "HardwareKeywordDetector.h"
#include "../audio/audio_manager.h"

namespace media {
namespace voice {

HardwareKeywordDetector::HardwareKeywordDetector(int card, int device)
	: mCard(card)
	, mDevice(device)
{

}

bool HardwareKeywordDetector::init(uint32_t samprate, uint8_t channels)
{
	audio_manager_result_t result;

	result = register_stream_in_device_process_type(
		mCard, mDevice,
		AUDIO_DEVICE_PROCESS_TYPE_SPEECH_DETECTOR,
		AUDIO_DEVICE_SPEECH_DETECT_KD);

	if (result != AUDIO_MANAGER_SUCCESS) {
		meddbg("Error: register_stream_in_device_process_type(%d, %d) failed!\n", mCard, mDevice);
		return false;
	}

	result = register_stream_in_device_process_handler(
		mCard, mDevice,
		AUDIO_DEVICE_PROCESS_TYPE_SPEECH_DETECTOR);

	if (result != AUDIO_MANAGER_SUCCESS) {
		meddbg("Error: register_stream_in_device_process_handler(%d, %d) failed!\n", mCard, mDevice);
		return false;
	}

	return true;
}

void HardwareKeywordDetector::deinit()
{
	audio_manager_result_t result;

	result = unregister_stream_in_device_process(mCard, mDevice);

	if (result != AUDIO_MANAGER_SUCCESS) {
		meddbg("Error: unregister_stream_in_device_process(%d, %d) failed!\n", mCard, mDevice);
	}
}

void *HardwareKeywordDetector::keywordDetectThread(void *param)
{
	audio_manager_result_t result;
	uint16_t msgId;

	HardwareKeywordDetector *detector = (HardwareKeywordDetector *)param;

	while (true) {
		result = get_device_process_handler_message(detector->mCard, detector->mDevice, &msgId);

		if (result == AUDIO_MANAGER_SUCCESS) {
			if (msgId == AUDIO_DEVICE_SPEECH_DETECT_KD) {
				medvdbg("#### KD DETECTED!! ####\n");
				break;
			}
		} else if (result == AUDIO_MANAGER_INVALID_DEVICE) {
			meddbg("Error: device doesn't support it!!!\n");
			break;
		}

		usleep(30 * 1000);
	}

	stop_stream_in_device_process(detector->mCard, detector->mDevice);

	return NULL;
}

bool HardwareKeywordDetector::startKeywordDetect(uint32_t timeout)
{
	audio_manager_result_t result;
	pthread_t kd_thread;
	pthread_attr_t attr;

	medvdbg("startKeywordDetect for %d %d\n", mCard, mDevice);

	result = start_stream_in_device_process(mCard, mDevice);

	if (result != AUDIO_MANAGER_SUCCESS) {
		meddbg("Error: start_stream_in_device_process(%d, %d) failed!\n", mCard, mDevice);
		return false;
	}

	pthread_attr_init(&attr);
	pthread_attr_setstacksize(&attr, 1024);
	int ret = pthread_create(&kd_thread, &attr, static_cast<pthread_startroutine_t>(HardwareKeywordDetector::keywordDetectThread), this);
	if (ret != 0) {
		meddbg("Fail to create worker thread, return value : %d\n", ret);
		return false;
	}
	pthread_setname_np(kd_thread, "kd_thread");

	void *thread_ret = 0;

	medvdbg("### pthread join\n");
	pthread_join(kd_thread, &thread_ret);

	medvdbg("### pthread return: %d\n", thread_ret);

	return true;
}

} // namespace voice
} // namespace media
