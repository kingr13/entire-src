const PMAP_PORT = 111;       /* portmapper port number */
 /*
  * A mapping of (program, version, protocol) to port number
  */
 struct pmap {
     rpcprog_t prog;
     rpcvers_t vers;
     rpcprot_t prot;
     rpcport_t port;
 };
 /*
  * Supported values for the "prot" field
  */
 const IPPROTO_TCP = 6; /* protocol number for TCP/IP */
 const IPPROTO_UDP = 17; /* protocol number for UDP/IP */
 /*
  * A list of mappings
  */
 struct pmaplist {
     pmap map;
     pmaplist *next;
 };
 /*
  * Arguments to callit
  
 struct call_args {
     rpcprog_t prog;
 rpcvers_t vers;
 rpcproc_t proc;
     opaque args<>;
 };
 
 * Results of callit
/
 struct call_result {
     rpcport_t port;
     opaque res<>;
 };
 /*
 * Port mapper procedures
 */
 program PMAP_PROG {
     version PMAP_VERS {
         void
         PMAPPROC_NULL(void) = 0;
         bool
         PMAPPROC_SET(pmap) = 1;
         bool
         PMAPPROC_UNSET(pmap) = 2;
         unsigned int
         PMAPPROC_GETPORT(pmap) = 3;
         pmaplist
         PMAPPROC_DUMP(void) = 4;
     } = 2;
 } = 100000;
