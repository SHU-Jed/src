#	$NetBSD: Makefile,v 1.2 2003/09/13 20:18:11 lukem Exp $

.include <bsd.own.mk>

PROG=	showfont

LDADD+=	-lFS
DPADD+=	${LIBFS}

.PATH:	${X11SRCDIR.xc}/programs/${PROG}

.include <bsd.x11.mk>
.include <bsd.prog.mk>
