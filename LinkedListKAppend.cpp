#include<iostream>
using namespace std;
class List
{
    public:
    int data;
    List *next;
};

void display(List *start)
{
    if(start==NULL){
        cout<<"Empty";
        return;
    }
    List *curr=start;
    //cout<<"\n";
    while(curr->next!=NULL)
    {
        cout<<curr->data<<" ";
        curr=curr->next;
    }
    cout<<curr->data;
    cout<<"\n";
}
List* addfront(List *start,int data)
{

    List *temp=new List();
    temp->data=data;
    temp->next=NULL;
    if(start==NULL){
            start=temp;
    return start;

    }
    temp->next=start;
    start=temp;
    return start;
}

List* addrear(List *start,int data)
{
    List *temp=new List;
    temp->data=data;
    temp->next=NULL;
    if(start==NULL){
            start=temp;
    return start;

    }
    List *curr=start;
    while(curr->next!=NULL){
        curr=curr->next;
    }
    curr->next=temp;
    return start;

}

List* deleteend(List * start)
{
    if(start==NULL){
            cout<<"Empty List";
        return start;
    }
    if(start->next==NULL)
    {
        delete(start);
        start=NULL;
        return NULL;
    }
    List *t=start;
    while((t->next)->next!=NULL)
    {
        t=t->next;
    }
    delete(t->next);
    t->next=NULL;
    return start;

}

List* kAppend(List *start,int k)
{
    for(int i=0;i<k;i++)
    {
        List *curr=start;
        while(curr->next!=NULL)
        {
            curr=curr->next;
        }
        int data=curr->data;
        start=addfront(start,data);
        start=deleteend(start);
    }
    return start;
}

int main()
{
   List *start=NULL;
   int n;
   cin>>n;
   for(int i=0;i<n;i++)
   {
       int data;
       cin>>data;
       start=addrear(start,data);
   }
   int k;
   cin>>k;
   start=kAppend(start,k);
   display(start);
}
