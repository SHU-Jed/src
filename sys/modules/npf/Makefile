# $NetBSD: Makefile,v 1.10 2012/08/12 03:35:14 rmind Exp $

.include "../Makefile.inc"

.PATH:		${S}/net/npf

KMOD=		npf

SRCS=		npf.c npf_alg.c npf_ctl.c npf_handler.c
SRCS+=		npf_inet.c npf_instr.c npf_log.c npf_mbuf.c npf_nat.c
SRCS+=		npf_processor.c npf_ruleset.c npf_rproc.c npf_sendpkt.c
SRCS+=		npf_session.c npf_state.c npf_state_tcp.c
SRCS+=		npf_tableset.c npf_tableset_ptree.c

CPPFLAGS+=	-DINET6

.include <bsd.kmodule.mk>
