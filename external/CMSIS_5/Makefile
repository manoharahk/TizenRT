###########################################################################
#
# Copyright 2016 Samsung Electronics All Rights Reserved.
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
# http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing,
# software distributed under the License is distributed on an
# "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND,
# either express or implied. See the License for the specific
# language governing permissions and limitations under the License.
#
###########################################################################
############################################################################
# external/grpc/Makefile
#
#   Copyright (C) 2012 Gregory Nutt. All rights reserved.
#   Author: Gregory Nutt <gnutt@nuttx.org>
#
# Redistribution and use in source and binary forms, with or without
# modification, are permitted provided that the following conditions
# are met:
#
# 1. Redistributions of source code must retain the above copyright
#    notice, this list of conditions and the following disclaimer.
# 2. Redistributions in binary form must reproduce the above copyright
#    notice, this list of conditions and the following disclaimer in
#    the documentation and/or other materials provided with the
#    distribution.
# 3. Neither the name NuttX nor the names of its contributors may be
#    used to endorse or promote products derived from this software
#    without specific prior written permission.
#
# THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
# "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
# LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
# FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
# COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
# INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
# BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS
# OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED
# AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
# LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
# ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
# POSSIBILITY OF SUCH DAMAGE.
#
############################################################################

-include $(TOPDIR)/.config
-include $(TOPDIR)/Make.defs

ASRCS		=
CSRCS		= 

ifeq ($(CONFIG_CMSIS_DSP),y)
CFLAGS += -I CMSIS/DSP/Include/
CFLAGS += -I CMSIS/Core/Include/

CSRCS += CMSIS/DSP/Source/ComplexMathFunctions/arm_cmplx_mult_real_q15.c
CSRCS += CMSIS/DSP/Source/ComplexMathFunctions/arm_cmplx_mag_q15.c
CSRCS += CMSIS/DSP/Source/ComplexMathFunctions/arm_cmplx_mult_cmplx_q31.c
CSRCS += CMSIS/DSP/Source/ComplexMathFunctions/arm_cmplx_conj_q31.c
CSRCS += CMSIS/DSP/Source/ComplexMathFunctions/arm_cmplx_mult_real_q31.c
CSRCS += CMSIS/DSP/Source/ComplexMathFunctions/arm_cmplx_mag_q31.c
CSRCS += CMSIS/DSP/Source/ComplexMathFunctions/arm_cmplx_mag_squared_f32.c
CSRCS += CMSIS/DSP/Source/ComplexMathFunctions/arm_cmplx_mult_cmplx_q15.c
CSRCS += CMSIS/DSP/Source/ComplexMathFunctions/arm_cmplx_mag_f32.c
CSRCS += CMSIS/DSP/Source/ComplexMathFunctions/arm_cmplx_conj_f32.c
CSRCS += CMSIS/DSP/Source/ComplexMathFunctions/arm_cmplx_dot_prod_f32.c
CSRCS += CMSIS/DSP/Source/ComplexMathFunctions/arm_cmplx_mag_squared_q31.c
CSRCS += CMSIS/DSP/Source/ComplexMathFunctions/arm_cmplx_mag_squared_q15.c
CSRCS += CMSIS/DSP/Source/ComplexMathFunctions/arm_cmplx_dot_prod_q31.c
CSRCS += CMSIS/DSP/Source/ComplexMathFunctions/arm_cmplx_mult_cmplx_f32.c
CSRCS += CMSIS/DSP/Source/ComplexMathFunctions/arm_cmplx_dot_prod_q15.c
CSRCS += CMSIS/DSP/Source/ComplexMathFunctions/arm_cmplx_conj_q15.c
CSRCS += CMSIS/DSP/Source/ComplexMathFunctions/arm_cmplx_mult_real_f32.c
CSRCS += CMSIS/DSP/Source/CommonTables/arm_const_structs.c
CSRCS += CMSIS/DSP/Source/CommonTables/arm_common_tables.c
CSRCS += CMSIS/DSP/Source/SupportFunctions/arm_fill_q31.c
CSRCS += CMSIS/DSP/Source/SupportFunctions/arm_fill_q15.c
CSRCS += CMSIS/DSP/Source/SupportFunctions/arm_q7_to_float.c
CSRCS += CMSIS/DSP/Source/SupportFunctions/arm_q31_to_q15.c
CSRCS += CMSIS/DSP/Source/SupportFunctions/arm_fill_q7.c
CSRCS += CMSIS/DSP/Source/SupportFunctions/arm_q15_to_q7.c
CSRCS += CMSIS/DSP/Source/SupportFunctions/arm_copy_q7.c
CSRCS += CMSIS/DSP/Source/SupportFunctions/arm_copy_f32.c
CSRCS += CMSIS/DSP/Source/SupportFunctions/arm_q31_to_q7.c
CSRCS += CMSIS/DSP/Source/SupportFunctions/arm_float_to_q31.c
CSRCS += CMSIS/DSP/Source/SupportFunctions/arm_q15_to_float.c
CSRCS += CMSIS/DSP/Source/SupportFunctions/arm_copy_q15.c
CSRCS += CMSIS/DSP/Source/SupportFunctions/arm_q31_to_float.c
CSRCS += CMSIS/DSP/Source/SupportFunctions/arm_q7_to_q31.c
CSRCS += CMSIS/DSP/Source/SupportFunctions/arm_fill_f32.c
CSRCS += CMSIS/DSP/Source/SupportFunctions/arm_q15_to_q31.c
CSRCS += CMSIS/DSP/Source/SupportFunctions/arm_q7_to_q15.c
CSRCS += CMSIS/DSP/Source/SupportFunctions/arm_float_to_q15.c
CSRCS += CMSIS/DSP/Source/SupportFunctions/arm_copy_q31.c
CSRCS += CMSIS/DSP/Source/SupportFunctions/arm_float_to_q7.c
CSRCS += CMSIS/DSP/Source/BasicMathFunctions/arm_negate_q7.c
CSRCS += CMSIS/DSP/Source/BasicMathFunctions/arm_abs_f32.c
CSRCS += CMSIS/DSP/Source/BasicMathFunctions/arm_scale_q31.c
CSRCS += CMSIS/DSP/Source/BasicMathFunctions/arm_scale_q15.c
CSRCS += CMSIS/DSP/Source/BasicMathFunctions/arm_shift_q15.c
CSRCS += CMSIS/DSP/Source/BasicMathFunctions/arm_scale_f32.c
CSRCS += CMSIS/DSP/Source/BasicMathFunctions/arm_dot_prod_f32.c
CSRCS += CMSIS/DSP/Source/BasicMathFunctions/arm_dot_prod_q31.c
CSRCS += CMSIS/DSP/Source/BasicMathFunctions/arm_add_q15.c
CSRCS += CMSIS/DSP/Source/BasicMathFunctions/arm_offset_q31.c
CSRCS += CMSIS/DSP/Source/BasicMathFunctions/arm_negate_q15.c
CSRCS += CMSIS/DSP/Source/BasicMathFunctions/arm_sub_q7.c
CSRCS += CMSIS/DSP/Source/BasicMathFunctions/arm_dot_prod_q7.c
CSRCS += CMSIS/DSP/Source/BasicMathFunctions/arm_add_f32.c
CSRCS += CMSIS/DSP/Source/BasicMathFunctions/arm_shift_q31.c
CSRCS += CMSIS/DSP/Source/BasicMathFunctions/arm_mult_q15.c
CSRCS += CMSIS/DSP/Source/BasicMathFunctions/arm_shift_q7.c
CSRCS += CMSIS/DSP/Source/BasicMathFunctions/arm_offset_q15.c
CSRCS += CMSIS/DSP/Source/BasicMathFunctions/arm_sub_f32.c
CSRCS += CMSIS/DSP/Source/BasicMathFunctions/arm_sub_q15.c
CSRCS += CMSIS/DSP/Source/BasicMathFunctions/arm_dot_prod_q15.c
CSRCS += CMSIS/DSP/Source/BasicMathFunctions/arm_add_q7.c
CSRCS += CMSIS/DSP/Source/BasicMathFunctions/arm_mult_q31.c
CSRCS += CMSIS/DSP/Source/BasicMathFunctions/arm_abs_q7.c
CSRCS += CMSIS/DSP/Source/BasicMathFunctions/arm_offset_f32.c
CSRCS += CMSIS/DSP/Source/BasicMathFunctions/arm_scale_q7.c
CSRCS += CMSIS/DSP/Source/BasicMathFunctions/arm_mult_q7.c
CSRCS += CMSIS/DSP/Source/BasicMathFunctions/arm_abs_q31.c
CSRCS += CMSIS/DSP/Source/BasicMathFunctions/arm_sub_q31.c
CSRCS += CMSIS/DSP/Source/BasicMathFunctions/arm_offset_q7.c
CSRCS += CMSIS/DSP/Source/BasicMathFunctions/arm_negate_f32.c
CSRCS += CMSIS/DSP/Source/BasicMathFunctions/arm_abs_q15.c
CSRCS += CMSIS/DSP/Source/BasicMathFunctions/arm_add_q31.c
CSRCS += CMSIS/DSP/Source/BasicMathFunctions/arm_mult_f32.c
CSRCS += CMSIS/DSP/Source/BasicMathFunctions/arm_negate_q31.c
CSRCS += CMSIS/DSP/Source/TransformFunctions/arm_cfft_radix2_q31.c
CSRCS += CMSIS/DSP/Source/TransformFunctions/arm_cfft_radix4_init_q15.c
CSRCS += CMSIS/DSP/Source/TransformFunctions/arm_dct4_f32.c
CSRCS += CMSIS/DSP/Source/TransformFunctions/arm_cfft_radix8_f32.c
CSRCS += CMSIS/DSP/Source/TransformFunctions/arm_cfft_radix2_q15.c
CSRCS += CMSIS/DSP/Source/TransformFunctions/arm_cfft_f32.c
CSRCS += CMSIS/DSP/Source/TransformFunctions/arm_cfft_q31.c
CSRCS += CMSIS/DSP/Source/TransformFunctions/arm_rfft_init_q31.c
CSRCS += CMSIS/DSP/Source/TransformFunctions/arm_cfft_radix4_init_q31.c
CSRCS += CMSIS/DSP/Source/TransformFunctions/arm_cfft_radix4_q15.c
CSRCS += CMSIS/DSP/Source/TransformFunctions/arm_dct4_init_f32.c
CSRCS += CMSIS/DSP/Source/TransformFunctions/arm_dct4_q15.c
CSRCS += CMSIS/DSP/Source/TransformFunctions/arm_rfft_f32.c
CSRCS += CMSIS/DSP/Source/TransformFunctions/arm_cfft_radix4_f32.c
CSRCS += CMSIS/DSP/Source/TransformFunctions/arm_rfft_fast_init_f32.c
CSRCS += CMSIS/DSP/Source/TransformFunctions/arm_rfft_init_f32.c
CSRCS += CMSIS/DSP/Source/TransformFunctions/arm_cfft_radix4_q31.c
CSRCS += CMSIS/DSP/Source/TransformFunctions/arm_dct4_q31.c
CSRCS += CMSIS/DSP/Source/TransformFunctions/arm_rfft_fast_f32.c
CSRCS += CMSIS/DSP/Source/TransformFunctions/arm_bitreversal.c
CSRCS += CMSIS/DSP/Source/TransformFunctions/arm_rfft_init_q15.c
CSRCS += CMSIS/DSP/Source/TransformFunctions/arm_cfft_q15.c
CSRCS += CMSIS/DSP/Source/TransformFunctions/arm_dct4_init_q31.c
CSRCS += CMSIS/DSP/Source/TransformFunctions/arm_dct4_init_q15.c
CSRCS += CMSIS/DSP/Source/TransformFunctions/arm_rfft_q15.c
CSRCS += CMSIS/DSP/Source/TransformFunctions/arm_cfft_radix2_init_f32.c
CSRCS += CMSIS/DSP/Source/TransformFunctions/arm_cfft_radix4_init_f32.c
CSRCS += CMSIS/DSP/Source/TransformFunctions/arm_rfft_q31.c
CSRCS += CMSIS/DSP/Source/TransformFunctions/arm_cfft_radix2_init_q15.c
CSRCS += CMSIS/DSP/Source/TransformFunctions/arm_cfft_radix2_f32.c
CSRCS += CMSIS/DSP/Source/TransformFunctions/arm_cfft_radix2_init_q31.c
CSRCS += CMSIS/DSP/Source/MatrixFunctions/arm_mat_scale_q31.c
CSRCS += CMSIS/DSP/Source/MatrixFunctions/arm_mat_add_f32.c
CSRCS += CMSIS/DSP/Source/MatrixFunctions/arm_mat_mult_f32.c
CSRCS += CMSIS/DSP/Source/MatrixFunctions/arm_mat_sub_f32.c
CSRCS += CMSIS/DSP/Source/MatrixFunctions/arm_mat_inverse_f64.c
CSRCS += CMSIS/DSP/Source/MatrixFunctions/arm_mat_mult_fast_q15.c
CSRCS += CMSIS/DSP/Source/MatrixFunctions/arm_mat_cmplx_mult_f32.c
CSRCS += CMSIS/DSP/Source/MatrixFunctions/arm_mat_scale_q15.c
CSRCS += CMSIS/DSP/Source/MatrixFunctions/arm_mat_trans_q15.c
CSRCS += CMSIS/DSP/Source/MatrixFunctions/arm_mat_add_q15.c
CSRCS += CMSIS/DSP/Source/MatrixFunctions/arm_mat_init_f32.c
CSRCS += CMSIS/DSP/Source/MatrixFunctions/arm_mat_mult_fast_q31.c
CSRCS += CMSIS/DSP/Source/MatrixFunctions/arm_mat_cmplx_mult_q31.c
CSRCS += CMSIS/DSP/Source/MatrixFunctions/arm_mat_cmplx_mult_q15.c
CSRCS += CMSIS/DSP/Source/MatrixFunctions/arm_mat_init_q31.c
CSRCS += CMSIS/DSP/Source/MatrixFunctions/arm_mat_trans_q31.c
CSRCS += CMSIS/DSP/Source/MatrixFunctions/arm_mat_inverse_f32.c
CSRCS += CMSIS/DSP/Source/MatrixFunctions/arm_mat_sub_q15.c
CSRCS += CMSIS/DSP/Source/MatrixFunctions/arm_mat_mult_q31.c
CSRCS += CMSIS/DSP/Source/MatrixFunctions/arm_mat_init_q15.c
CSRCS += CMSIS/DSP/Source/MatrixFunctions/arm_mat_trans_f32.c
CSRCS += CMSIS/DSP/Source/MatrixFunctions/arm_mat_scale_f32.c
CSRCS += CMSIS/DSP/Source/MatrixFunctions/arm_mat_sub_q31.c
CSRCS += CMSIS/DSP/Source/MatrixFunctions/arm_mat_mult_q15.c
CSRCS += CMSIS/DSP/Source/MatrixFunctions/arm_mat_add_q31.c
CSRCS += CMSIS/DSP/Source/FastMathFunctions/arm_cos_q31.c
CSRCS += CMSIS/DSP/Source/FastMathFunctions/arm_sin_f32.c
CSRCS += CMSIS/DSP/Source/FastMathFunctions/arm_cos_f32.c
CSRCS += CMSIS/DSP/Source/FastMathFunctions/arm_sin_q15.c
CSRCS += CMSIS/DSP/Source/FastMathFunctions/arm_sqrt_q31.c
CSRCS += CMSIS/DSP/Source/FastMathFunctions/arm_cos_q15.c
CSRCS += CMSIS/DSP/Source/FastMathFunctions/arm_sqrt_q15.c
CSRCS += CMSIS/DSP/Source/FastMathFunctions/arm_sin_q31.c
CSRCS += CMSIS/DSP/Source/ControllerFunctions/arm_pid_reset_q15.c
CSRCS += CMSIS/DSP/Source/ControllerFunctions/arm_pid_init_q15.c
CSRCS += CMSIS/DSP/Source/ControllerFunctions/arm_pid_init_f32.c
CSRCS += CMSIS/DSP/Source/ControllerFunctions/arm_sin_cos_q31.c
CSRCS += CMSIS/DSP/Source/ControllerFunctions/arm_sin_cos_f32.c
CSRCS += CMSIS/DSP/Source/ControllerFunctions/arm_pid_reset_f32.c
CSRCS += CMSIS/DSP/Source/ControllerFunctions/arm_pid_init_q31.c
CSRCS += CMSIS/DSP/Source/ControllerFunctions/arm_pid_reset_q31.c
CSRCS += CMSIS/DSP/Source/FilteringFunctions/arm_conv_opt_q7.c
CSRCS += CMSIS/DSP/Source/FilteringFunctions/arm_fir_sparse_init_q7.c
CSRCS += CMSIS/DSP/Source/FilteringFunctions/arm_fir_lattice_init_f32.c
CSRCS += CMSIS/DSP/Source/FilteringFunctions/arm_fir_init_q15.c
CSRCS += CMSIS/DSP/Source/FilteringFunctions/arm_biquad_cascade_stereo_df2T_init_f32.c
CSRCS += CMSIS/DSP/Source/FilteringFunctions/arm_lms_q15.c
CSRCS += CMSIS/DSP/Source/FilteringFunctions/arm_correlate_opt_q7.c
CSRCS += CMSIS/DSP/Source/FilteringFunctions/arm_lms_init_f32.c
CSRCS += CMSIS/DSP/Source/FilteringFunctions/arm_fir_sparse_init_q31.c
CSRCS += CMSIS/DSP/Source/FilteringFunctions/arm_biquad_cascade_df2T_f64.c
CSRCS += CMSIS/DSP/Source/FilteringFunctions/arm_conv_q31.c
CSRCS += CMSIS/DSP/Source/FilteringFunctions/arm_correlate_fast_q31.c
CSRCS += CMSIS/DSP/Source/FilteringFunctions/arm_conv_fast_q31.c
CSRCS += CMSIS/DSP/Source/FilteringFunctions/arm_fir_decimate_q31.c
CSRCS += CMSIS/DSP/Source/FilteringFunctions/arm_fir_decimate_f32.c
CSRCS += CMSIS/DSP/Source/FilteringFunctions/arm_conv_fast_opt_q15.c
CSRCS += CMSIS/DSP/Source/FilteringFunctions/arm_fir_decimate_init_q15.c
CSRCS += CMSIS/DSP/Source/FilteringFunctions/arm_biquad_cascade_df1_init_q15.c
CSRCS += CMSIS/DSP/Source/FilteringFunctions/arm_fir_sparse_init_f32.c
CSRCS += CMSIS/DSP/Source/FilteringFunctions/arm_fir_decimate_init_q31.c
CSRCS += CMSIS/DSP/Source/FilteringFunctions/arm_biquad_cascade_df1_32x64_init_q31.c
CSRCS += CMSIS/DSP/Source/FilteringFunctions/arm_fir_lattice_init_q31.c
CSRCS += CMSIS/DSP/Source/FilteringFunctions/arm_conv_partial_fast_opt_q15.c
CSRCS += CMSIS/DSP/Source/FilteringFunctions/arm_conv_q15.c
CSRCS += CMSIS/DSP/Source/FilteringFunctions/arm_biquad_cascade_df1_f32.c
CSRCS += CMSIS/DSP/Source/FilteringFunctions/arm_biquad_cascade_df2T_f32.c
CSRCS += CMSIS/DSP/Source/FilteringFunctions/arm_fir_lattice_init_q15.c
CSRCS += CMSIS/DSP/Source/FilteringFunctions/arm_iir_lattice_q15.c
CSRCS += CMSIS/DSP/Source/FilteringFunctions/arm_lms_norm_q15.c
CSRCS += CMSIS/DSP/Source/FilteringFunctions/arm_fir_decimate_fast_q31.c
CSRCS += CMSIS/DSP/Source/FilteringFunctions/arm_biquad_cascade_df1_init_f32.c
CSRCS += CMSIS/DSP/Source/FilteringFunctions/arm_correlate_f32.c
CSRCS += CMSIS/DSP/Source/FilteringFunctions/arm_biquad_cascade_df1_q31.c
CSRCS += CMSIS/DSP/Source/FilteringFunctions/arm_lms_f32.c
CSRCS += CMSIS/DSP/Source/FilteringFunctions/arm_fir_sparse_q7.c
CSRCS += CMSIS/DSP/Source/FilteringFunctions/arm_biquad_cascade_df1_32x64_q31.c
CSRCS += CMSIS/DSP/Source/FilteringFunctions/arm_correlate_q15.c
CSRCS += CMSIS/DSP/Source/FilteringFunctions/arm_fir_decimate_fast_q15.c
CSRCS += CMSIS/DSP/Source/FilteringFunctions/arm_biquad_cascade_stereo_df2T_f32.c
CSRCS += CMSIS/DSP/Source/FilteringFunctions/arm_conv_q7.c
CSRCS += CMSIS/DSP/Source/FilteringFunctions/arm_conv_partial_fast_q15.c
CSRCS += CMSIS/DSP/Source/FilteringFunctions/arm_fir_interpolate_q31.c
CSRCS += CMSIS/DSP/Source/FilteringFunctions/arm_biquad_cascade_df1_q15.c
CSRCS += CMSIS/DSP/Source/FilteringFunctions/arm_lms_norm_init_f32.c
CSRCS += CMSIS/DSP/Source/FilteringFunctions/arm_conv_partial_q7.c
CSRCS += CMSIS/DSP/Source/FilteringFunctions/arm_correlate_fast_opt_q15.c
CSRCS += CMSIS/DSP/Source/FilteringFunctions/arm_biquad_cascade_df1_fast_q31.c
CSRCS += CMSIS/DSP/Source/FilteringFunctions/arm_conv_partial_q31.c
CSRCS += CMSIS/DSP/Source/FilteringFunctions/arm_fir_q31.c
CSRCS += CMSIS/DSP/Source/FilteringFunctions/arm_fir_sparse_q31.c
CSRCS += CMSIS/DSP/Source/FilteringFunctions/arm_conv_partial_fast_q31.c
CSRCS += CMSIS/DSP/Source/FilteringFunctions/arm_fir_interpolate_init_q15.c
CSRCS += CMSIS/DSP/Source/FilteringFunctions/arm_fir_fast_q31.c
CSRCS += CMSIS/DSP/Source/FilteringFunctions/arm_conv_partial_q15.c
CSRCS += CMSIS/DSP/Source/FilteringFunctions/arm_correlate_opt_q15.c
CSRCS += CMSIS/DSP/Source/FilteringFunctions/arm_fir_interpolate_init_q31.c
CSRCS += CMSIS/DSP/Source/FilteringFunctions/arm_fir_sparse_q15.c
CSRCS += CMSIS/DSP/Source/FilteringFunctions/arm_fir_init_q7.c
CSRCS += CMSIS/DSP/Source/FilteringFunctions/arm_fir_sparse_init_q15.c
CSRCS += CMSIS/DSP/Source/FilteringFunctions/arm_fir_lattice_q15.c
CSRCS += CMSIS/DSP/Source/FilteringFunctions/arm_conv_partial_f32.c
CSRCS += CMSIS/DSP/Source/FilteringFunctions/arm_fir_init_q31.c
CSRCS += CMSIS/DSP/Source/FilteringFunctions/arm_iir_lattice_init_q31.c
CSRCS += CMSIS/DSP/Source/FilteringFunctions/arm_lms_init_q15.c
CSRCS += CMSIS/DSP/Source/FilteringFunctions/arm_biquad_cascade_df2T_init_f64.c
CSRCS += CMSIS/DSP/Source/FilteringFunctions/arm_correlate_q7.c
CSRCS += CMSIS/DSP/Source/FilteringFunctions/arm_fir_interpolate_f32.c
CSRCS += CMSIS/DSP/Source/FilteringFunctions/arm_biquad_cascade_df1_init_q31.c
CSRCS += CMSIS/DSP/Source/FilteringFunctions/arm_conv_fast_q15.c
CSRCS += CMSIS/DSP/Source/FilteringFunctions/arm_fir_interpolate_q15.c
CSRCS += CMSIS/DSP/Source/FilteringFunctions/arm_conv_opt_q15.c
CSRCS += CMSIS/DSP/Source/FilteringFunctions/arm_fir_lattice_f32.c
CSRCS += CMSIS/DSP/Source/FilteringFunctions/arm_iir_lattice_f32.c
CSRCS += CMSIS/DSP/Source/FilteringFunctions/arm_fir_interpolate_init_f32.c
CSRCS += CMSIS/DSP/Source/FilteringFunctions/arm_lms_norm_init_q15.c
CSRCS += CMSIS/DSP/Source/FilteringFunctions/arm_lms_norm_f32.c
CSRCS += CMSIS/DSP/Source/FilteringFunctions/arm_correlate_fast_q15.c
CSRCS += CMSIS/DSP/Source/FilteringFunctions/arm_iir_lattice_init_f32.c
endif

ifeq ($(CONFIG_CMSIS_NN),y)
CFLAGS += -I CMSIS/NN/Include/

CSRCS += CMSIS/NN/Source/NNSupportFunctions/arm_nntables.c
CSRCS += CMSIS/NN/Source/NNSupportFunctions/arm_q7_to_q15_no_shift.c
CSRCS += CMSIS/NN/Source/NNSupportFunctions/arm_nn_mult_q15.c
CSRCS += CMSIS/NN/Source/NNSupportFunctions/arm_nn_mult_q7.c
CSRCS += CMSIS/NN/Source/NNSupportFunctions/arm_q7_to_q15_reordered_no_shift.c
CSRCS += CMSIS/NN/Source/ActivationFunctions/arm_nn_activations_q7.c
CSRCS += CMSIS/NN/Source/ActivationFunctions/arm_relu_q7.c
CSRCS += CMSIS/NN/Source/ActivationFunctions/arm_relu_q15.c
CSRCS += CMSIS/NN/Source/ActivationFunctions/arm_nn_activations_q15.c
CSRCS += CMSIS/NN/Source/FullyConnectedFunctions/arm_fully_connected_mat_q7_vec_q15_opt.c
CSRCS += CMSIS/NN/Source/FullyConnectedFunctions/arm_fully_connected_q15_opt.c
CSRCS += CMSIS/NN/Source/FullyConnectedFunctions/arm_fully_connected_mat_q7_vec_q15.c
CSRCS += CMSIS/NN/Source/FullyConnectedFunctions/arm_fully_connected_q15.c
CSRCS += CMSIS/NN/Source/FullyConnectedFunctions/arm_fully_connected_q7_opt.c
CSRCS += CMSIS/NN/Source/FullyConnectedFunctions/arm_fully_connected_q7.c
CSRCS += CMSIS/NN/Source/SoftmaxFunctions/arm_softmax_q7.c
CSRCS += CMSIS/NN/Source/SoftmaxFunctions/arm_softmax_q15.c
CSRCS += CMSIS/NN/Source/ConvolutionFunctions/arm_convolve_HWC_q7_basic_nonsquare.c
CSRCS += CMSIS/NN/Source/ConvolutionFunctions/arm_convolve_1x1_HWC_q7_fast_nonsquare.c
CSRCS += CMSIS/NN/Source/ConvolutionFunctions/arm_nn_mat_mult_kernel_q7_q15.c
CSRCS += CMSIS/NN/Source/ConvolutionFunctions/arm_convolve_HWC_q7_fast.c
CSRCS += CMSIS/NN/Source/ConvolutionFunctions/arm_nn_mat_mult_kernel_q7_q15_reordered.c
CSRCS += CMSIS/NN/Source/ConvolutionFunctions/arm_convolve_HWC_q15_basic.c
CSRCS += CMSIS/NN/Source/ConvolutionFunctions/arm_depthwise_separable_conv_HWC_q7_nonsquare.c
CSRCS += CMSIS/NN/Source/ConvolutionFunctions/arm_convolve_HWC_q7_RGB.c
CSRCS += CMSIS/NN/Source/ConvolutionFunctions/arm_convolve_HWC_q7_basic.c
CSRCS += CMSIS/NN/Source/ConvolutionFunctions/arm_convolve_HWC_q15_fast_nonsquare.c
CSRCS += CMSIS/NN/Source/ConvolutionFunctions/arm_depthwise_separable_conv_HWC_q7.c
CSRCS += CMSIS/NN/Source/ConvolutionFunctions/arm_convolve_HWC_q7_fast_nonsquare.c
CSRCS += CMSIS/NN/Source/ConvolutionFunctions/arm_convolve_HWC_q15_fast.c
CSRCS += CMSIS/NN/Source/PoolingFunctions/arm_pool_q7_HWC.c
endif

AOBJS		= $(ASRCS:.S=$(OBJEXT))
COBJS		= $(CSRCS:.c=$(OBJEXT))

SRCS		= $(ASRCS) $(CSRCS)
OBJS		= $(AOBJS) $(COBJS)

ifeq ($(CONFIG_WINDOWS_NATIVE),y)
  BIN		= ..\libexternal$(LIBEXT)
else
ifeq ($(WINTOOL),y)
  BIN		= ..\\libexternal$(LIBEXT)
else
  BIN		= ../libexternal$(LIBEXT)
endif
endif

DEPPATH	= --dep-path .

# Common build

VPATH		=

all: .built
.PHONY: depend clean distclean

$(AOBJS): %$(OBJEXT): %.S
	$(call ASSEMBLE, $<, $@)

$(COBJS): %$(OBJEXT): %.c
	$(call COMPILE, $<, $@)

.built: $(OBJS)
	$(call ARCHIVE, $(BIN), $(OBJS))
	$(Q) touch .built

.depend: Makefile $(SRCS)
	$(Q) $(MKDEP) $(DEPPATH) "$(CC)" -- $(CFLAGS) -- $(SRCS) >Make.dep
	$(Q) touch $@

depend: .depend

clean:
	$(call DELFILE, .built)
	$(call CLEAN)
	$(Q) find . -name "*.o" -exec rm -rf {} \;

distclean: clean
	$(call DELFILE, Make.dep)
	$(call DELFILE, .depend)

-include Make.dep

