#	$NetBSD: Makefile,v 1.32 2012/03/23 21:31:27 christos Exp $

.include <bsd.own.mk>

SUBDIR=	acpica am-utils bind cron dhcpcd fetch file flex less libarchive \
	libevent liblzf libpcap mdocml openresolv top byacc wpa ntp tcpdump \
	tmux tre

.if (${MKATF} != "no")
SUBDIR+= atf
.endif
.if (${MKISCSI} != "no")
SUBDIR+= iscsi 
.endif
.if (${MKLDAP} != "no")
SUBDIR+= openldap
.endif
.if (${MKLLVM} != "no")
SUBDIR+= llvm
.endif
.if (${MKCRYPTO} != "no")
SUBDIR+= pkg_install ../../crypto/external/bsd
.endif
.if (${MKPCC} != "no")
SUBDIR+= pcc
.endif
# IP Filter
.if (${MKIPFILTER} != "no")
SUBDIR+=ipf
.endif

.include <bsd.subdir.mk>
