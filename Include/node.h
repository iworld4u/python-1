#ifndef Py_NODE_H
#define Py_NODE_H
#ifdef __cplusplus
extern "C" {
#endif

/***********************************************************
Copyright 1991-1995 by Stichting Mathematisch Centrum, Amsterdam,
The Netherlands.

                        All Rights Reserved

Copyright (c) 2000, BeOpen.com.
Copyright (c) 1995-2000, Corporation for National Research Initiatives.
Copyright (c) 1990-1995, Stichting Mathematisch Centrum.
All rights reserved.

See the file "Misc/COPYRIGHT" for information on usage and
redistribution of this file, and for a DISCLAIMER OF ALL WARRANTIES.

******************************************************************/

/* Parse tree node interface */

typedef struct _node {
	short		n_type;
	char		*n_str;
	short		n_lineno;
	short		n_nchildren;
	struct _node	*n_child;
} node;

extern DL_IMPORT(node *) PyNode_New Py_PROTO((int type));
extern DL_IMPORT(int) PyNode_AddChild Py_PROTO((node *n, int type, char *str, int lineno));
extern DL_IMPORT(void) PyNode_Free Py_PROTO((node *n));

/* Node access functions */
#define NCH(n)		((n)->n_nchildren)
#define CHILD(n, i)	(&(n)->n_child[i])
#define TYPE(n)		((n)->n_type)
#define STR(n)		((n)->n_str)

/* Assert that the type of a node is what we expect */
#ifndef Py_DEBUG
#define REQ(n, type) { /*pass*/ ; }
#else
#define REQ(n, type) \
	{ if (TYPE(n) != (type)) { \
		fprintf(stderr, "FATAL: node type %d, required %d\n", \
			TYPE(n), type); \
		abort(); \
	} }
#endif

extern DL_IMPORT(void) PyNode_ListTree Py_PROTO((node *));

#ifdef __cplusplus
}
#endif
#endif /* !Py_NODE_H */
