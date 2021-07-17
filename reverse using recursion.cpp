#include <bits/stdc++.h>
using namespace std;   
struct node{              
	int data;
	node* next;
};
struct  node* insert(struct node* head,int n)    //function for inserting a node in link list//
{
	node* newn=(struct node*)malloc(sizeof(struct node));
	if(head==NULL)
	{
		newn->data=n;
		newn->next=NULL;
		head=newn;
	}
	else{
		newn->data=n;
		newn->next=head;
		head=newn;
	}
	return head;
}
void print(node* head)         //function to print link list in forward direction//
{
	if(head==NULL)
		return;
	cout<<head->data<<" ";
	print(head->next);
}
void reverse_print(node* head)	       //function to print link list in backward direction//	
{
	if(head==NULL)
		return;
	reverse_print(head->next);
	cout<<head->data<<" ";
}
int main()
{
	
	node* head=NULL;
	head=insert(head,2);
	head=insert(head,8);
	head=insert(head,19);
	head=insert(head,29);
	print(head);
	cout<<endl;
	reverse_print(head);
	
}
