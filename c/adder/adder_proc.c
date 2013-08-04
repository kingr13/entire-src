#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <gmp.h>
#include  "adder.h"				/* msg.h generated by rpcgen */

char **adder_1(struct operation **opn, CLIENT *req)
{
    printf("Solving!");
  
    mpz_t n11, n12, n13;
    mpz_init(n11);
    mpz_init(n12);
    mpz_init(n13);
    mpz_set_str(n11, (*opn)->op1, 10);
    mpz_set_str(n12, (*opn)->op2, 10);
    switch((*opn)->operator) {
        case '+':
        mpz_add(n13, n11, n12);
        break;
        
        case '-':
        mpz_sub(n13, n11, n12);
        break;

        case '*':
        mpz_mul(n13, n11, n12);
        break;

        
        case '/':
        mpz_cdiv_q(n13, n11, n12);
        break;
    }
    
    FILE *f;
 
	f = fopen("/home/aman/console", "w");
	if (f == (FILE *)NULL) {
		return NULL;
	}
	fprintf(f, "%s\n", "dfdf");
	fclose(f);
    
    char *str = malloc(1000);
    mpz_get_str(str, 10, n13);
    static char *result;
    result = str;
    return &result;
}
