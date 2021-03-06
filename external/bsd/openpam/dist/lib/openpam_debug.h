/*	$NetBSD: openpam_debug.h,v 1.2 2011/12/25 22:27:55 christos Exp $	*/

/*-
 * Copyright (c) 2001-2003 Networks Associates Technology, Inc.
 * Copyright (c) 2004-2011 Dag-Erling Smørgrav
 * All rights reserved.
 *
 * This software was developed for the FreeBSD Project by ThinkSec AS and
 * Network Associates Laboratories, the Security Research Division of
 * Network Associates, Inc.  under DARPA/SPAWAR contract N66001-01-C-8035
 * ("CBOSS"), as part of the DARPA CHATS research program.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. The name of the author may not be used to endorse or promote
 *    products derived from this software without specific prior written
 *    permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 *
 * Id: openpam_debug.h 491 2011-11-12 00:12:32Z des
 */

#ifndef OPENPAM_DEBUG_INCLUDED
#define OPENPAM_DEBUG_INCLUDED

#ifdef OPENPAM_DEBUG
#define ENTER() openpam_log(PAM_LOG_DEBUG, "entering")
#define ENTERI(i) do { \
	int i_ = (i); \
	if (i_ > 0 && i_ < PAM_NUM_ITEMS) \
		openpam_log(PAM_LOG_DEBUG, "entering: %s", pam_item_name[i_]); \
	else \
		openpam_log(PAM_LOG_DEBUG, "entering: %d", i_); \
} while (/*CONSTCOND*/0)
#define ENTERN(n) do { \
	int n_ = (n); \
	openpam_log(PAM_LOG_DEBUG, "entering: %d", n_); \
} while (/*CONSTCOND*/0)
#define ENTERS(s) do { \
	const char *s_ = (s); \
	if (s_ == NULL) \
		openpam_log(PAM_LOG_DEBUG, "entering: NULL"); \
	else \
		openpam_log(PAM_LOG_DEBUG, "entering: '%s'", s_); \
} while (/*CONSTCOND*/0)
#define	RETURNV() openpam_log(PAM_LOG_DEBUG, "returning")
#define RETURNC(c) do { \
	int c_ = (c); \
	if (c_ >= 0 && c_ < PAM_NUM_ERRORS) \
		openpam_log(PAM_LOG_DEBUG, "returning %s", pam_err_name[c_]); \
	else \
		openpam_log(PAM_LOG_DEBUG, "returning %d!", c_); \
	return (c_); \
} while (/*CONSTCOND*/0)
#define	RETURNN(n) do { \
	int n_ = (n); \
	openpam_log(PAM_LOG_DEBUG, "returning %d", n_); \
	return (n_); \
} while (/*CONSTCOND*/0)
#define	RETURNP(p) do { \
	const void *p_ = (p); \
	if (p_ == NULL) \
		openpam_log(PAM_LOG_DEBUG, "returning NULL"); \
	else \
		openpam_log(PAM_LOG_DEBUG, "returning %p", p_); \
	return (p_); \
} while (/*CONSTCOND*/0)
#define	RETURNS(s) do { \
	const char *s_ = (s); \
	if (s_ == NULL) \
		openpam_log(PAM_LOG_DEBUG, "returning NULL"); \
	else \
		openpam_log(PAM_LOG_DEBUG, "returning '%s'", s_); \
	return (s_); \
} while (/*CONSTCOND*/0)
#else
#define ENTER()
#define ENTERI(i)
#define ENTERN(n)
#define ENTERS(s)
#define RETURNV() return
#define RETURNC(c) return (c)
#define RETURNN(n) return (n)
#define RETURNP(p) return (p)
#define RETURNS(s) return (s)
#endif

#endif
