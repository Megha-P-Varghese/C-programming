#include<stdio.h>
#include<malloc.h>
struct node
{
	int data;
	struct node * next;
};
struct node* head = NULL;
void insert(int e)
{
	struct node * temp;
	if(head==NULL)
	{
		head =(struct node*)malloc (sizeof(struct node));
		head->data=e;
		head->next=NULL;
	}
	else
	{
		temp=head;
		while(temp->next!=NULL)
		{
			temp=temp->next;
		}
		temp->next=(struct node*)malloc (sizeof (struct node));
		temp->next->data=e;
		temp->next->next=NULL;
	}
}
void disp()
{
	struct node * temp;
	if(head==NULL)
	{
		printf("linked list empty");
	}
	else
	{
		temp=head;
		while(temp!=NULL)
		{
			printf("%d\t",temp->data);
			temp=temp->next;
		}
	}
}
int main()
{
	insert(10);
	insert(20);
	insert(30);
	disp();
}
