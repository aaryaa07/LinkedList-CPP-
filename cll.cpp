#include<iostream>
using namespace std;
class cnode{
	public:

		int data;
		cnode* next;
		cnode(int d)
		{
			data=d;
			

		}

};
void insertList(cnode*& head,int data)//push
{
	cnode* temp=new cnode(data);
	temp->next=temp;
	
	if (head==NULL)
	{
		head=temp;
		
		

	}
	cnode* c=head;
	while(c->next!=head)
	{
		c=c->next;
	}
	c->next=temp;
	temp->next=head;
	
}
void print(cnode* head)
{
	cnode *c=head;
	while(c->next!=head)
	{
		cout<<c->data<<"->";
		c=c->next;
	}
	cout<<c->data<<"->";
	cout<<c->next->data<<endl;
}
void delNode(cnode*& head)//pop
{
	if (head==NULL)
	{
		
		return;
	}
	else if(head->next==head)
	{
		
		delete head;
	}
	else
	{
		
		cnode* temp=head;
		cnode* c=head;
		
		while(c->next!=head)
		{
			c=c->next;

		}

		c->next=head->next;
		head=head->next;
		
		delete temp;

	}
}
int main()
{
	
	cnode* head=NULL;
	int n;
	cout<<"Enter no. of nos. you want to append to the list"<<endl;
	cin>>n;
	while(n!=0)
	{
		int x;
		cin>>x;
		insertList(head,x);//appends element in the end
		n--;
	}
	print(head);
	delNode(head);//pops the first element that came in
	print(head);//functioning like a queue -> the first element to get in will be the first element to be out (FIFO)


}