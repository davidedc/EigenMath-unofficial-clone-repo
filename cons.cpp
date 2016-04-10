// Cons two things on the stack.

#include "stdafx.h"
#include "defs.h"

int consCount = 0;

void
cons(void)
{
    consCount++;
    // auto var ok, no opportunity for garbage collection after p = alloc()
    printf("cons tos: %d # %d\n", tos, consCount);
    if (consCount == 444) {
        printf("stop here");
    }
    U *p;
	p = alloc();
	p->k = CONS;
	p->u.cons.cdr = pop();
	p->u.cons.car = pop();
    
    /*
    printf("cons new cdr.k = %u\nor more in detail:\n", p->u.cons.cdr->k);
    print1(p->u.cons.cdr);
    printf("\n");
    printf("cons new car.k = %u\nor more in detail:\n", p->u.cons.car->k);
    print1(p->u.cons.car);
    printf("\n");
     */
	push(p);
}
