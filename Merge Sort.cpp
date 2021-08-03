/* c++ program for sorting
	a link list using 
	merge sort technique */

#include<bits/stdc++.h>
using namespace std;

/* link list node */
class node{
	public:
	int data;
	node* next;
	node(int n)
	{
		data=n;
		next=NULL;
	}
};

/* function for insert node in link list */ 
node* insert(node* head, int data)
{
	node* new_n = new node(data);
	if(head == NULL)
		head = new_n;
	else{
		new_n->next = head;
		head = new_n;
	}
	return head;
}

/* function for display link list */
void display(node* head)
{
	while(head!=NULL)
	{
		cout<<head->data<<" ";
		head = head->next;
	}
	cout<<endl;
}

/* function to find middle of link list */
void FindMiddle(node* curr, node** first, node** second)
{
		
	node* slow = curr;
	node* fast = curr->next;
	
	while(fast != NULL)
	{
		fast = fast->next;
		if(fast!=NULL)
		{
			slow = slow->next;
			fast = fast->next;
		}
	}
	*first = curr;
	*second = slow->next;
	slow->next = NULL;
}

/* function for merge sort technique */
node* merge_sort(node* first, node* second)
{
	node* answer = NULL;
	
	if(!first)				// if first contains NULL then return second
		return second;
	else if(!second)		// vice versa	
		return first;
	if( first->data <= second->data )
	{
		
		answer = first;
		answer->next = merge_sort(first->next, second);
	}
	else{
		answer = second;
		answer->next = merge_sort(first, second->next);
	}
	return answer;
}

/* function for sorting the link list */
void sort(node** head)
{
	node* curr = *head;
	node* first=NULL;
	node* second=NULL;
	
	if(!curr || !curr->next)
		return;

	FindMiddle(curr, &first, &second);
	
	sort(&first);
	sort(&second);
	
	*head = merge_sort(first, second);
}
int main()
{
	node* head = NULL;
	head = insert(head,2);
	head = insert(head,1);
	head = insert(head,3);
	head = insert(head,7);
	head = insert(head,4);
	head = insert(head,9);
	head = insert(head,5);
	display(head);
	sort(&head);
	display(head);
}
