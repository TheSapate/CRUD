#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
	int data;
	struct node *next;
	struct node *prev;
}NODE,*PNODE,**PPNODE;

void Display(PNODE Head)
{
    while (Head != NULL)
    {
        printf("|%d| -> ",Head->data);
        Head = Head -> next;
    }
    
    printf(" NULL\n");
}
void InsertFirst(PPNODE Head,int no)
{
	PNODE newn=NULL;
	newn=(PNODE)malloc(sizeof(NODE));
	
	newn->data=no;
	newn->next=NULL;
	newn->prev=NULL;
	
	if(*Head == NULL)
    {
        *Head = newn;
    }
    else
    {
        newn -> next = *Head;
        (*Head) ->prev = newn;
        
        *Head = newn;
    }
}
void InsertLast(PPNODE Head,int no)
{
	PNODE newn=NULL;
	PNODE temp=*Head;
	
	newn=(PNODE)malloc(sizeof(NODE));
	
	newn->data=no;
	newn->next=NULL;
	newn->prev=NULL;
	
	while(temp->next!=NULL)
	{
		temp=temp->next;
	}
	temp->next=newn;
	newn->prev=temp;
}
void DeleteFirst(PPNODE Head)
{
	if(*Head==NULL)
	{
		return;
	}
	else if((*Head)->next==NULL)
	{
		free(*Head);
		*Head=NULL;
	}
	else
	{
		*Head=(*Head)->next;
		free((*Head)->prev);
		(*Head)->prev=NULL;
	}
}
void DeleteLast(PPNODE Head)
{
	PNODE temp=*Head;
	int i=0;
	if(*Head==NULL)
	{
		return;
	}
	else if((*Head)->next==NULL)
	{
		free(*Head);
		*Head=NULL;
	}
	else
	{
		while(temp->next!=NULL)
		{
			temp=temp->next;
		}
		temp->prev->next=NULL;
		free(temp);
	}
}
void DeleteAtPos(PPNODE Head,int Pos)
{
	PNODE temp=*Head;
	PNODE target=NULL;
	int i=0;
	if(Pos<0)
	{
		return;
	}
	else
	{
	for(i=1;i<Pos;i++)
	{
		temp=temp->next;
	}
	temp->next=temp->next->next;
	free(temp->next->prev);
	temp->next->prev=temp;
	}
}
int main()
{
	PNODE first=NULL;
	
	InsertFirst(&first,10);
	InsertFirst(&first,20);
	InsertFirst(&first,30);
	
	InsertLast(&first,40);
	InsertLast(&first,50);
	InsertLast(&first,60);
	
	DeleteFirst(&first);
	DeleteLast(&first);
	
	//DeleteAtPos(&first,3);
	
	//DeleteAtPos(&first,3);
	
	printf("Elemenet of Linked list are\n");
    Display(first);
	
	return 0;
}
