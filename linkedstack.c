#include<stdio.h>
#include<malloc.h>
struct node
{
	int data;
	struct node *next;
};
struct node *top=NULL;
void push(int x)
{
	struct node *newnode;
	newnode=(struct node *)malloc(sizeof(struct node));
	newnode->data=x;
	newnode->next=top;
	top=newnode;
}

void peek()
{
	
	if(top==NULL)
	{
		printf("stack underflow");
	}
	else
	{
		printf("\ntop element is %d",top->data);
	}
	
}
void pop()
{
	struct node *temp;
	temp=top;
	if(top==NULL)
	{
		printf("underflow");
	}
	else
	{
		printf("\npopped element is %d",top->data);
		top=top->next;
		free(temp);
		
	}
}
int main()
{
	push(10);
	push(20);
	push(30);
	push(40);
	peek();
	pop();
	peek();
	pop();
	peek();
	printf("\n");
	return 0;
}
