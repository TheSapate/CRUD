#include<stdio.h>
#include<stdlib.h>
 
struct node
{
	int Data;
	struct node *next;
};

typedef struct node NODE;
typedef struct node * PNODE;
typedef struct node ** PPNODE;

int main()
{
	PNODE p=NULL;
	PPNODE q=NULL;

	p=(PNODE)malloc(sizeof(NODE));  //Dynamic Memory Allocation of Structure
	q=&p;
	
	return 0;
}