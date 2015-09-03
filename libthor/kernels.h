/*
Copyright (c) 2015, Cisco Systems
All rights reserved.

Redistribution and use in source and binary forms, with or without modification,
are permitted provided that the following conditions are met:

* Redistributions of source code must retain the above copyright notice, this
  list of conditions and the following disclaimer.

* Redistributions in binary form must reproduce the above copyright notice, this
  list of conditions and the following disclaimer in the documentation and/or
  other materials provided with the distribution.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

#ifndef THOR_KERNELS_H
#define THOR_KERNELS_H

#include <stdint.h>
#include "simd.h"

void get_inter_prediction_int_simd(int width, int height, int xoff, int yoff,
				  uint8_t* RESTRICT qp, int qstride, const uint8_t* RESTRICT ip, int istride);
void get_inter_prediction_luma_simd(int width, int height, int xoff, int yoff,
				    uint8_t* RESTRICT qp, int qstride, const uint8_t* RESTRICT ip, int istride);
void get_inter_prediction_chroma_simd(int width, int height, int xoff, int yoff,
				      uint8_t* RESTRICT qp, int qstride, const uint8_t* RESTRICT ip, int istride);
void transform_simd(const int16_t *block, int16_t *coeff, int size, int fast);
void inverse_transform_simd(const int16_t* coeff, int16_t* block, int size);

int sad_calc_simd(uint8_t *a, uint8_t *b, int astride, int bstride, int width, int height);
int ssd_calc_simd(uint8_t *a, uint8_t *b, int astride, int bstride, int size);

#endif /* THOR_KERNELS_H */
