#	$NetBSD: Makefile,v 1.13 2011/05/20 13:38:52 joerg Exp $

REQUIRETOOLS=	yes
NOLINT=		# defined

UNSUPPORTED_COMPILER.clang=	# defined

.include <bsd.own.mk>

LIB=		objc

.if ${MKGCC} != "no"

SHLIB_MAJOR=	3
SHLIB_MINOR=	0

# XXX just while all platforms defs.mk are updated..
.if exists(${.CURDIR}/arch/${MACHINE_ARCH}/defs.mk)
# Machine-dependent definitions (include file names).
.include "${.CURDIR}/arch/${MACHINE_ARCH}/defs.mk"
EXTRA_FAKEHEADERS=
.else
# Machine-independent definitions (include file names).
.include "${.CURDIR}/defs.mk"
EXTRA_FAKEHEADERS=	options.h
.endif

LIBGCCOBJ!=    cd ${.CURDIR}/../libgcc4/libgcc && ${PRINTOBJDIR}

DIST=		${NETBSDSRCDIR}/gnu/dist/gcc4
GNUHOSTDIST=	${NETBSDSRCDIR}/gnu/dist/gcc4
GCCARCH=	${NETBSDSRCDIR}/gnu/usr.bin/gcc4/arch/${MACHINE_ARCH}
LIBOBJCARCH=	${NETBSDSRCDIR}/gnu/lib/libobjc4/arch/${MACHINE_ARCH}
GCCLIBXX=	${NETBSDSRCDIR}/gnu/lib/libstdc++-v3_4/arch/${MACHINE_ARCH}

SRCS=		${G_OBJS:N[A-Z]*:Nlinking.lo:.lo=.c} ${G_OBJS:M[A-Z]*:.lo=.m} linking.m

GCPPFLAGS=	${G_ALL_CFLAGS} ${G_INCLUDES}
CPPFLAGS+=	-I. -I${.CURDIR}/arch/${MACHINE_ARCH}
CPPFLAGS+=	-I${GCCARCH} ${GCPPFLAGS:M-D*} ${GCPPFLAGS:M-I*:N-I.*}
CPPFLAGS+=	-I${GCCLIBXX}

BUILDSYMLINKS=	${.CURDIR}/../libstdc++-v3_4/arch/${MACHINE_ARCH} bits
DPSRCS+=	bits

.for f in Protocol.m Object.m NXConstStr.m linking.m
OBJCOPTS.${f}=	-fgnu-runtime
.endfor

.for f in thr.c thr-objc.c
COPTS.${f}=	-Wno-missing-noreturn
.endfor

COPTS+=		-fno-strict-aliasing -fexceptions
OBJCOPTS+=	-fno-strict-aliasing -fexceptions

OBJCOPTS.Object.m = -Wno-stack-protector
COPTS.sendmsg.c = -Wno-stack-protector

INCS=		${G_OBJC_H}
INCSDIR=	/usr/include/objc

DPSRCS+=	runtime-info.h
CLEANFILES+=	rtscratch rtscratch.s runtime-info.h
runtime-info.h:
	${_MKTARGET_CREATE}
	touch rtscratch
	`${OBJC} --print-prog-name=cc1obj` -print-objc-runtime-info rtscratch >$@

.PATH: ${DIST}/libobjc ${DIST}/libobjc/objc

.include <bsd.lib.mk>

${OBJS} ${POBJS} ${SOBJS}: runtime-info.h

# these aren't necessary but are #include'd
FAKEHEADERS=	${EXTRA_FAKEHEADERS} insn-flags.h insn-constants.h
${FAKEHEADERS}:
	${_MKTARGET_CREATE}
	touch ${.TARGET}
tm.h ${SRCS}: ${FAKEHEADERS}
CLEANFILES+=	${FAKEHEADERS}

${SRCS}: tconfig.h unwind.h options.h

tconfig.h:
	${_MKTARGET_CREATE}
	TARGET_CPU_DEFAULT="" \
	HEADERS="$(G_xm_include_list)" DEFINES="USED_FOR_TARGET $(G_xm_defines)" \
	${HOST_SH} $(GNUHOSTDIST)/gcc/mkconfig.sh tconfig.h

unwind.h: ${G_UNWIND_H}
	${_MKTARGET_CREATE}
	rm -f ${.TARGET}
	ln -s ${G_UNWIND_H} ${.TARGET}

CLEANFILES+= cs-tconfig.h tconfig.h unwind.h

# XXX just while all platforms defs.mk are updated..
.if exists(${.CURDIR}/arch/${MACHINE_ARCH}/defs.mk)
optionlist: ${G_ALL_OPT_FILES} ${LIBOBJCARCH}/defs.mk Makefile ${DIST}/gcc/opt-gather.awk
	${TOOL_AWK} -f ${DIST}/gcc/opt-gather.awk ${G_ALL_OPT_FILES} \
		> ${.TARGET}

options.h: optionlist ${DIST}/gcc/opt-functions.awk ${DIST}/gcc/opth-gen.awk
	${TOOL_AWK} -f ${DIST}/gcc/opt-functions.awk \
		-f ${DIST}/gcc/opth-gen.awk \
		< optionlist > ${.TARGET}

CLEANFILES+=	options.h optionlist
.endif

.else
.include <bsd.prog.mk>	# do nothing
.endif
