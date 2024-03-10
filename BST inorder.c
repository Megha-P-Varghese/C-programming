#include<stdio.h>
#include<malloc.h>
struct node{
	int data;
	struct node *left;
	struct node *right;
};
struct node * root=NULL;
void insert(int e)
{
		struct node *p,*x;
		if(root==NULL)
		{
				root=(struct node*)malloc(sizeof(struct node));
				root->data=e;
				root->left=NULL;
				root->right=NULL;
		}else
	{
		p=root;
		while(p!=NULL)
		{
				x=p;
				if(p->data>e)
				{
					p=p->left;
				}
				else
				{
					p=p->right;
				}
		}
		if(x->data<e)
		{
				x->right=(struct node*)malloc(sizeof(struct node));
				x->right->data=e;
				x->right->left=NULL;
				x->right->right=NULL;
		}
		else
		{
				x->left=(struct node*)malloc(sizeof(struct node));
				x->left->data=e;
				x->left->left=NULL;
				x->left->right=NULL;
		}
	}
}
void inorder(struct node* r)
{
		if(r!=NULL)
		{
			inorder(r->left);
			printf("%d\t",r->data);
			inorder(r->right);
		}
}

int main()
{
	
		insert(20);
		insert(30);
		inorder(root);
	
	
}
