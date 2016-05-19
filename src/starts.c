/* -*- mode: C; tab-width: 2; indent-tabs-mode: nil; -*- */

/*
 * This code has been contributed by the DARPA HPCS program.  Contact
 * David Koester <dkoester@mitre.org> or Bob Lucas <rflucas@isi.edu>
 * if you have questions.
 */

/* June 2013
 * Converted the MPI+SHMEM version to SGI/OpenSHMEM version.
 * The call to the MPI functions have been commented but not
 * removed for ease of future experiments with support for
 * hybrid models.
 * Author: Siddhartha Jana
 */

/*
 * OpenSHMEM version:
 *
 * Copyright (c) 2011 - 2015
 *   University of Houston System and UT-Battelle, LLC.
 *
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * o Redistributions of source code must retain the above copyright notice,
 *   this list of conditions and the following disclaimer.
 *
 * o Redistributions in binary form must reproduce the above copyright
 *   notice, this list of conditions and the following disclaimer in the
 *   documentation and/or other materials provided with the distribution.
 *
 * o Neither the name of the University of Houston System,
 *   UT-Battelle, LLC. nor the names of its contributors may be used to
 *   endorse or promote products derived from this software without specific
 *   prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 * HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED
 * TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
 * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 */

#include "RandomAccess.h"

/* Utility routine to start random number generator at Nth step */

int64_t
starts(uint64_t n)
{
	/* int64_t i, j; */
	int i, j;
	uint64_t m2[64];
	uint64_t temp, ran;

	while (n < 0)
		n += PERIOD;
	while (n > PERIOD)
		n -= PERIOD;
	if (n == 0)
		return 0x1;

	temp = 0x1;
	for (i=0; i<64; i++) {
		m2[i] = temp;
		temp = (temp << 1) ^ ((int64_t) temp < 0 ? POLY : 0);
		temp = (temp << 1) ^ ((int64_t) temp < 0 ? POLY : 0);
	}

	for (i=62; i>=0; i--)
		if ((n >> i) & 1) break;

	ran = 0x2;

	while (i > 0) {
		temp = 0;
		for (j=0; j<64; j++)
			if ((ran >> j) & 1) temp ^= m2[j];
		ran = temp;
		i -= 1;
		if ((n >> i) & 1)
			ran = (ran << 1) ^ ((int64_t) ran < 0 ? POLY : 0);
	}

	return ran;
}
