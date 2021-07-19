// Iterative C++ program to reverse
// a linked list
#include<iostream>
using namespace std;
/* Link list node */
class node{
	public:
	int data;
	node* next;
};
node* head=NULL;
void insert(int value)   //function for inserting a node in the list
{
	node* new_node=new node();
	if(head==NULL){
		new_node->data=value;
		new_node->next=NULL;
		head=new_node;
	}
	else{
		new_node->data=value;
		new_node->next=head;
		head=new_node;
	}
	return;
}
void display()			//function  for print the list
{
	node* temp=head;
	while(temp!=NULL)
	{
		cout<<temp->data<<" ";
		temp=temp->next;
	}
	return;
}
void reverse()			//function to reverse a given list;
{
	node* prev=NULL;
	node* curr=head;
	node* next=NULL;
	while(curr!=NULL)
	{
		// Before changing next of current, 
		// store next node 
		next=curr->next;
		// Now change next of current 
		// This is where actual reversing happens 
		curr->next=prev;
		// Move prev and curr one step forward 
		prev=curr;
		curr=next;
	}
	head=prev;
}
int main()
{
	insert(5);
	insert(10);
	insert(15);
	insert(20);
	cout<<"The given list is : ";
	display();
	reverse();
	cout<<endl<<endl;
	cout<<"The reversed list is : ";
	display();
}
