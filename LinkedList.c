//
// Created by taylor on 9/18/16.
//

#include <stdlib.h>
#include "LinkedList.h"

LLNode* newNode()
{
	LLNode* node;
	node=(LLNode*)malloc(sizeof(LLNode));
	node->right=NULL;
	node->left=NULL;
	node->value=0;

	return node;
}