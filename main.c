/*
 * main.c
 *
 *  Created on: 24 de set de 2016
 *      Author: leony
 */

#include "huffnode.h"

int main()
{
	int items[256], i;
	Priority_Queue *pq = create_priority_queue();
	for (i = 0; i < 256; i++){
		if (items[i] > 0){
			Node *new_node = create_node((char)i, items[i]);
			enqueue_sorted(pq, new_node);
		}
	}
	print_queue(pq);
	Node *root = NULL;
	root = build_tree(pq);
	int size;
	size = tree_size(root);
	return 0;
}
