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
 * Title:        arm_lu_bounded_relu_q15.c
 * Description:  Q15 version of ReLU
 *
 * $Date:        20. March 2019
 * $Revision:    V.1.0.0
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
   * @brief Q15 LU BOUNDED RELU function
   * @param[in,out]   data        pointer to input
   * @param[in]       size        number of elements
   * @return none.
   * 
   * @details
   *
   * Optimized relu with QSUB instructions.
   *
   */

void arm_lu_bounded_relu_q15(q15_t * data, q15_t ubound, q15_t lbound, uint16_t size)
{

#if defined (ARM_MATH_DSP)
    /* Run the following code for Cortex-M4 and Cortex-M7 */

    uint16_t  i = size >> 1;
    q15_t    *pIn = data;
    q15_t    *pOut = data;
    q31_t     in;
    q15_t    *pBuf;

    while (i)
    {
        in = *__SIMD32(pIn)++;

	pBuf = &in;

	pBuf[0] = min(ubound, max(pBuf[0], lbound));
	pBuf[1] = min(ubound, max(pBuf[1], lbound));

        *__SIMD32(pOut)++ = in;
        i--;
    }

    if (size & 0x1)
    {
	*pIn = min(ubound, max(*pIn, lbound));
        pIn++;
    }
#else
    /* Run the following code as reference implementation for Cortex-M0 and Cortex-M3 */
    uint16_t  i;

    for (i = 0; i < size; i++)
    {
	data[i] = min(ubound, max(data[i], lbound));
    }

#endif                          /* ARM_MATH_DSP */

}

/**
 * @} end of Acti group
 */
