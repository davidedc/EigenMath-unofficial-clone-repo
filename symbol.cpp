// The symbol table is a simple array of struct U.

#include "stdafx.h"
#include "defs.h"

// put symbol at index n

void
std_symbol(char *s, int n)
{
	U *p;
	p = symtab + n;
	p->u.printname = s;
}

// symbol lookup, create symbol if need be

U *
usr_symbol(char *s)
{
	int i;
	U *p;
	for (i = 0; i < NSYM; i++) {
		if (symtab[i].u.printname == 0)
			break;
		if (strcmp(s, symtab[i].u.printname) == 0)
			return symtab + i;
	}
	if (i == NSYM)
		stop("symbol table overflow");
	p = symtab + i;
	p->u.printname = strdup(s);
	return p;
}

// get the symbol's printname

char *
get_printname(U *p)
{
	if (p->k != SYM)
		stop("symbol error");
	return p->u.printname;
}

// clears the arglist too

void
set_binding(U *p, U *q)
{
	if (p->k != SYM)
		stop("symbol error");
    printf("lookup >> set_binding lookup %d\n", (int) (p - symtab));
	binding[p - symtab] = q;
	arglist[p - symtab] = symbol(NIL);
}

U *
get_binding(U *p)
{
	if (p->k != SYM)
		stop("symbol error");
    printf("lookup >> get_binding lookup %d\n", (int) (p - symtab));
    if ((int) (p - symtab) == 139)
        printf("debug here");
    //if ((int) (p - symtab) == 137)
    //    printf("debug here");
	return binding[p - symtab];
}

void
set_binding_and_arglist(U *p, U *q, U *r)
{
	if (p->k != SYM)
		stop("symbol error");
    printf("lookup >> set_binding_and_arglist lookup %d\n", (int) (p - symtab));
	binding[p - symtab] = q;
	arglist[p - symtab] = r;
}

U *
get_arglist(U *p)
{
	if (p->k != SYM)
		stop("symbol error");
    printf("lookup >> get_arglist lookup %d\n", (int) (p - symtab));
	return arglist[p - symtab];
}

// get symbol's number from ptr

int lookupsTotal = 0;

int
symnum(U *p)
{
    lookupsTotal++;
    if (p->k != SYM)
		stop("symbol error");
    printf("lookup >> symnum lookup %d lookup # %d\n", (int) (p - symtab), lookupsTotal);
    if (lookupsTotal == 21)
        printstr("stop here");
    if ((int) (p - symtab) == 79)
        printstr("stop here");
	return (int) (p - symtab);
}

// push indexed symbol

void
push_symbol(int k)
{
	push(symtab + k);
}

void
clear_symbols(void)
{
	int i;
	for (i = 0; i < NSYM; i++) {
		binding[i] = symtab + i;
		arglist[i] = symbol(NIL);
	}
}
