#include <stdio.h>
#include <stdlib.h> // Include stdlib.h for malloc function

struct node
{
    int data;
    struct node* next;
};

struct node* head = NULL;

void insert(int e)
{
    struct node* temp;
    if (head == NULL)
    {
        head = (struct node*)malloc(sizeof(struct node));
        head->data=e;
        head->next=NULL;
    }
    else
    {
        temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = (struct node*)malloc(sizeof(struct node));
        temp = temp->next; // Move to the newly created node
        temp->data = e;
        temp->next = NULL;
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

void sort()
{
	int t;
	struct node *t1,*t2;
	for(t1=head;t1 != NULL;t1 = t1->next)
	{
		for(t2=head;t2->next != NULL;t2 = t2->next)
		{
			if(t2->data > t2->next->data)
			{
				t = t2->data;
				t2->data = t2->next->data;
				t2->next->data = t;
			}
		}
	}
}
int main()
{
	insert(40);
	insert(20);
	insert(10);
	insert(30);
    sort();
    disp();
}
