/*	$NetBSD: pthread_md.h,v 1.7 2012/08/16 04:49:48 matt Exp $	*/

/*
 * Copyright (c) 2001 Wasabi Systems, Inc.
 * All rights reserved.
 *
 * Written by Jason R. Thorpe for Wasabi Systems, Inc.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. All advertising materials mentioning features or use of this software
 *    must display the following acknowledgement:
 *	This product includes software developed for the NetBSD Project by
 *	Wasabi Systems, Inc.
 * 4. The name of Wasabi Systems, Inc. may not be used to endorse
 *    or promote products derived from this software without specific prior
 *    written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY WASABI SYSTEMS, INC. ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED
 * TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL WASABI SYSTEMS, INC
 * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef _LIB_PTHREAD_ARM_MD_H
#define	_LIB_PTHREAD_ARM_MD_H

static inline unsigned long
pthread__sp(void)
{
	unsigned long ret;

	__asm volatile("mov %0, sp"
		: "=r" (ret));

	return (ret);
}

#define pthread__smt_pause()	__asm __volatile("wfe")
#define pthread__smt_wake()	__asm __volatile("sev")

#define	pthread__uc_sp(ucp)	((ucp)->uc_mcontext.__gregs[_REG_SP])

/*
 * Set initial, sane values for registers whose values aren't just
 * "don't care".
 */
#ifdef __APCS_26__
#define _INITCONTEXT_U_MD(ucp)						\
/* Set R15_MODE_USR in the PC */					\
	(ucp)->uc_mcontext.__gregs[_REG_PC] =				\
	 ((ucp)->uc_mcontext.__gregs[_REG_PC] & 0x3fffffc) | 0x0;
#else
/* Set CPSR to PSR_USE32_MODE (0x10) from arm/armreg.h */
#define _INITCONTEXT_U_MD(ucp)						\
	(ucp)->uc_mcontext.__gregs[_REG_CPSR] = 0x10;
#endif

#endif /* _LIB_PTHREAD_ARM_MD_H */
