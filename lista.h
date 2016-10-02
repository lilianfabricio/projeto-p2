#ifndef LISTA_H_
#define LISTA_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node_list NodeList;

typedef struct list List;

List* createlist();

void insertnode(List* l, unsigned char c);

int listsize(List* list);

unsigned char removenode(List* l);

#endif /* LISTA_H_ */
