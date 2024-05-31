#include<stdio.h>
#include<malloc.h>
struct node
{
	int data;
	struct node *next;
};
struct node *front=NULL;
struct node *rear=NULL;

void enqueue(int x)
{
	struct node *newnode;
	newnode=(struct node *)malloc(sizeof(struct node));
	newnode->data=x;
	newnode->next=0;
	if(front==0 && rear==0)
	{
	 front=rear=newnode;
	}
	else
	{
		rear->next=newnode;
		rear=newnode;
	}
}
void disp()
{
	struct node *temp;
	if(front==0&&rear==0)
	{
		printf("queue is empty");
	}
	else
	{
		temp=front;
		while(temp!=0)
		{
			printf("\n%d",temp->data);
			temp=temp->next;
		}
	}
}
void dequeue()
{
	struct node *temp;
	temp=front;
	if(front==0&&rear==0)
	{
		printf("queue is empty");
	}
	else
	{
		printf("\nthe dequeued element is %d",front->data);
		front=front->next;
		free (temp);
	}
}

	int main()
	{
		enqueue(10);
		enqueue(20);
		enqueue(30);
		disp();
		dequeue();
		printf("\n");
		return 0;
		
	}



