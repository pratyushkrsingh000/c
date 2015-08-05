#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "mem.h"

void *
zmalloc(int n) 
{
	void *v;

	v = malloc(n);
	if(!v) {
		fprintf(stderr, "out of memory\n");
		abort();
	}
	memset(v, 0, n);
	return v;
}

char *
zstrdup(char *s)
{
	int l;
	char *r;

	l = strlen(s);
	r = zmalloc(l + 1);
	strncpy(r, s, l);
	return r;
}
