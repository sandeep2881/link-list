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
int length()
{
	int n=0;
	node* temp=head;
	while(temp!=NULL)
	{
		n++;
		temp=temp->next;
	}
	return n;
}
node* reverse(node* head,int k)			//function to reverse a given list;
{
    // base case
    
    node* current = head;
    node* next = NULL;
    node* prev = NULL;
    int count = 0;
 
    /*reverse first k nodes of the linked list */
    while (current != NULL && count < k) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
        count++;
    }
 
    /* next is now a pointer to (k+1)th node
    Recursively call for the list starting from current.
    And make rest of the list as next of first node */
    if (next != NULL)
        head->next = reverse(next, k);
 
    /* prev is new head of the input list */
    return prev; 
}
int main()
{
	insert(5);
	insert(10);
	insert(15);
	insert(20);
	cout<<"The given list is : ";
	display();
	head=reverse(head,3);
	cout<<endl<<endl;
	cout<<"The reversed list is : ";
	display();
}
