/*
 * Copyright (C) 2010-2018 Arm Limited or its affiliates. All rights reserved.
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Licensed under the Apache License, Version 2.0 (the License); you may
 * not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an AS IS BASIS, WITHOUT
 * WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

/* ----------------------------------------------------------------------
 * Project:      CMSIS NN Library
 * Title:        arm_bounded_relu_q7.c
 * Description:  Q7 version of ReLU
 *
 * $Date:        8. March 2019
 * $Revision:    V.1.0.1
 *
 * Target Processor:  Cortex-M cores
 *
 * -------------------------------------------------------------------- */

#include "arm_math.h"
#include "arm_nnfunctions.h"

/**
 *  @ingroup groupNN
 */

#define min(a, b) (((a) < (b)) ? (a) : (b))
#define max(a, b) (((a) > (b)) ? (a) : (b))

/**
 * @addtogroup Acti
 * @{
 */

  /**
   * @brief Q7 BOUNDED RELU function
   * @param[in,out]   data        pointer to input
   * @param[in]       ubound      upper bound value
   * @param[in]       size        number of elements
   * @return none.
   * 
   * @details
   *
   * Optimized bounded relu with QSUB instructions.
   *
   */

void arm_lu_bounded_relu_q7(q7_t * data, q7_t ubound, q7_t lbound, uint16_t size)
{

#if defined (ARM_MATH_DSP)
    /* Run the following code for Cortex-M4 and Cortex-M7 */

    uint16_t  i = size >> 2;
    q7_t     *pIn = data;
    q7_t     *pOut = data;
    q31_t     in;
    q7_t      *pBuf;

    while (i)
    {
        in = *__SIMD32(pIn)++;

	pBuf = &in;

	pBuf[0] = min(ubound, max(pBuf[0], lbound));
	pBuf[1] = min(ubound, max(pBuf[1], lbound));
	pBuf[2] = min(ubound, max(pBuf[2], lbound));
	pBuf[3] = min(ubound, max(pBuf[3], lbound));

        *__SIMD32(pOut)++ = in;
        i--;
    }

    i = size & 0x3;
    while (i)
    {
	*pIn = min(ubound, max(*pIn, lbound));

        pIn++;
        i--;
    }

#else
    /* Run the following code as reference implementation for Cortex-M0 and Cortex-M3 */

    uint16_t  i;

    for (i = 0; i < size; i++)
    {
	data[i]  = min(ubound, max(data[i], lbound));
    }

#endif                          /* ARM_MATH_DSP */

}

/**
 * @} end of Acti group
 */
