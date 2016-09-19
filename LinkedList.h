//
// Created by taylor on 9/18/16.
//

#ifndef BRAINF_LINKEDLIST_H
#define BRAINF_LINKEDLIST_H

#include <stddef.h>

typedef struct LinkedListNode
{
	char value;
	struct LinkedListNode *right, *left;
} LLNode;

LLNode* newNode();


#endif //BRAINF_LINKEDLIST_H
