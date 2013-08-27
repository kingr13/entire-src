/*
 * Please do not edit this file.
 * It was generated using rpcgen.
 */

#include <memory.h> /* for memset */
#include "portmapper.h"

/* Default timeout can be changed using clnt_control() */
static struct timeval TIMEOUT = { 25, 0 };

void *
pmapproc_null_2(void *argp, CLIENT *clnt)
{
	static char clnt_res;

	memset((char *)&clnt_res, 0, sizeof(clnt_res));
	if (clnt_call (clnt, PMAPPROC_NULL,
		(xdrproc_t) xdr_void, (caddr_t) argp,
		(xdrproc_t) xdr_void, (caddr_t) &clnt_res,
		TIMEOUT) != RPC_SUCCESS) {
		return (NULL);
	}
	return ((void *)&clnt_res);
}

bool_t *
pmapproc_set_2(pmap *argp, CLIENT *clnt)
{
	static bool_t clnt_res;

	memset((char *)&clnt_res, 0, sizeof(clnt_res));
	if (clnt_call (clnt, PMAPPROC_SET,
		(xdrproc_t) xdr_pmap, (caddr_t) argp,
		(xdrproc_t) xdr_bool, (caddr_t) &clnt_res,
		TIMEOUT) != RPC_SUCCESS) {
		return (NULL);
	}
	return (&clnt_res);
}

bool_t *
pmapproc_unset_2(pmap *argp, CLIENT *clnt)
{
	static bool_t clnt_res;

	memset((char *)&clnt_res, 0, sizeof(clnt_res));
	if (clnt_call (clnt, PMAPPROC_UNSET,
		(xdrproc_t) xdr_pmap, (caddr_t) argp,
		(xdrproc_t) xdr_bool, (caddr_t) &clnt_res,
		TIMEOUT) != RPC_SUCCESS) {
		return (NULL);
	}
	return (&clnt_res);
}

u_int *
pmapproc_getport_2(pmap *argp, CLIENT *clnt)
{
	static u_int clnt_res;

	memset((char *)&clnt_res, 0, sizeof(clnt_res));
	if (clnt_call (clnt, PMAPPROC_GETPORT,
		(xdrproc_t) xdr_pmap, (caddr_t) argp,
		(xdrproc_t) xdr_u_int, (caddr_t) &clnt_res,
		TIMEOUT) != RPC_SUCCESS) {
		return (NULL);
	}
	return (&clnt_res);
}

pmaplist *
pmapproc_dump_2(void *argp, CLIENT *clnt)
{
	static pmaplist clnt_res;

	memset((char *)&clnt_res, 0, sizeof(clnt_res));
	if (clnt_call (clnt, PMAPPROC_DUMP,
		(xdrproc_t) xdr_void, (caddr_t) argp,
		(xdrproc_t) xdr_pmaplist, (caddr_t) &clnt_res,
		TIMEOUT) != RPC_SUCCESS) {
		return (NULL);
	}
	return (&clnt_res);
}
