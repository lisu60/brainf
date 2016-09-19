#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

#include "LinkedList.h"

int fd, len;
char* code;
unsigned long pc=0;
LLNode *ptr, *p;

void findLeftBrac()
{
	int depth=0;
	while(1)
	{
		pc--;
		if(code[pc]=='[')
		{
			if(depth==0)
				break;
			else
				depth--;
		}
		if(code[pc]==']')
			depth++;
	}
}

void findRightBrac()
{
	int depth=0;
	while(1)
	{
		pc++;
		if(code[pc]==']')
		{
			if(depth==0)
				break;
			else
				depth--;
		}
		if(code[pc]=='[')
			depth++;
	}
}

int main(int argc, char** argv) {
	if(argc<2)
	{
		printf("usage: %s file\n", argv[0]);
		return -1;
	}
	if((fd=open(argv[1], O_RDONLY))<0)
	{
		printf("cannot open file %s\n", argv[1]);
		return -1;
	}

	len=lseek(fd, 0, SEEK_END);
	lseek(fd, 0, SEEK_SET);

	code=(char*)malloc(len);
	read(fd, code, len);
	close(fd);

	ptr=newNode();
	while(pc<len)
	{
		switch(code[pc])
		{
			case '[':
				if(ptr->value==0)
					findRightBrac();
				break;
			case ']':
				if(ptr->value!=0)
					findLeftBrac();
				break;
			case '>':
				if(ptr->right==NULL)
				{
					ptr->right = newNode();
					ptr->right->left=ptr;
				}
				ptr=ptr->right;
				break;
			case '<':
				if(ptr->left==NULL)
				{
					ptr->left = newNode();
					ptr->left->right=ptr;
				}
				ptr=ptr->left;
				break;
			case '+':
				ptr->value++;
				break;
			case '-':
				ptr->value--;
				break;
			case '.':
				putchar(ptr->value);
				break;
			case ',':
				ptr->value=getchar();
				break;
			default:
				break;

		}
		pc++;
	}

	free(code);

	for(; ptr->left; ptr=ptr->left);
	while (ptr)
	{
		p=ptr;
		ptr=ptr->right;
		free(p);
	}


	return 0;
}