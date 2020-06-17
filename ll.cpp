#include<iostream>
using namespace std;
class node
{
	public:
			int data;
			node* next;
			node(int d)
			{
				data=d;
				next=NULL;

			}
};



void insertHead(node*&head,int data) //updating head
{
	node* n=new node(data);
	n->next=head;
	head=n;
}



void print(node* head)//dont want to update head
{
	while(head!=NULL)
	{
		cout<<head->data<<"-->";
		
		head=head->next;
	}
	cout<<"NULL"<<endl;
}



void insertEnd(node*& head,int data)
{
	node*n=new node(data);
	node* curr=head;
	while(curr->next!=NULL)
	{
		curr=curr->next;
	}
	curr->next=n;

}



void insertPos(node*&head,int data,int pos)
{
	if(pos==0)
	{
		node* n=new node(data);
		n->next=head;
		head=n;

	}

	else
	{
		node* n=new node(data);
		node* curr=head;
		node* c=NULL;
		while(pos!=0&&curr!=NULL)
		{
			c=curr;
			curr=curr->next;
			pos--;

		}
		if(curr!=NULL)
		{
			c->next=n;
			n->next=curr;
		}
		else
		{
			c->next=n;
			n->next=NULL;
		}


		
	}

}



void search(node* head,int ele)
{
	int flag=0;
	int pos=0;
	while(head->next!=NULL)
	{
		if(head->data==ele)
		{
			flag=1;
			cout<<ele<<" found at position "<<pos<<endl;
			break;
		}
		head=head->next;
		pos++;
	}
	if(flag==0)
	{
		cout<<ele<<" not present"<<endl;
	}

}



void deleteNode(node*& head,int ele)
{
	if(head->data==ele)
		{
			node* temp=head;
			head=head->next;
			delete temp;
			return;
		}
	node* del=head;
	node* curr=NULL;
	while(head->next!=NULL)
	{
		

		curr=del;
		del=del->next;
		if(del->data==ele)
		{
			curr->next=del->next;
			delete del;
			return;

		}

	}
}
void reverseList(node*& head)
{
	node* p=NULL;
	node* q=NULL;
	node* c=head;
	while(c!=NULL)
	{
		q=c;
		c=c->next;
		q->next=p;
		p=q;
	}
	head=q;
}


void recReverse(node*& head,node*& p,node*& q){
	if(head==NULL)
	{
		head=p;
		return;
	}
	p=head;
	head=head->next;
	p->next=q;
	q=p;
	recReverse(head,p,q);



}
void midptRunnerTech(node* head)
{
	node*p=head;
	node*q=head;
	while(p->next!=NULL&&p->next->next!=NULL)
	{
		p=p->next->next;
		q=q->next;
	}
	cout<<"midpoint is "<<q->data<<endl;
}


int main()
{
	node* head =NULL;
	insertHead(head,1);//1
	insertHead(head,2);//2->1
	insertHead(head,3);//3->2->1 
	insertEnd(head,4);//3->2->1->4
	insertEnd(head,5);//3->2->1->4->5
	insertPos(head,6,0);//6->3->2->1->4->5
	insertPos(head,7,1);//6->7->3->2->1->4->5
	insertPos(head,8,7);//6->7->3->2->1->4->5->8
	insertPos(head,9,14);//6->7->3->2->1->4->5->8->9, inserted at end as pos>length(list)
	print(head);
	search(head,5);//found
	search(head,20);//not found

	deleteNode(head,3);//6->7->2->1->4->5->8->9
	deleteNode(head,6);//7->2->1->4->5->8->9
	print(head);
	int n;
	cout<<"Enter no. of nos. you want to append to the list"<<endl;
	cin>>n;
	while(n!=0)
	{
		int x;
		cin>>x;
		insertEnd(head,x);
		n--;
	}
	print(head);//Linked List after appending elements taken in by user 
	reverseList(head);
	print(head);//Linked List after reversing the list
	node *p=NULL;
	node *q=NULL;
	recReverse(head,p,q);//Linked list after reversing the list recursively
	print(head);
	midptRunnerTech(head);//Midpoint of Linked List without calculating length of linked List

}
