 #include<iostream>
using namespace std;
class List
{
    public:
    int data;
    List *next;
};



List* reverseRecur(List *prev,List *curr,List *agla)
{
    if(agla==NULL)
    {
        curr->next=prev;
        return curr;
    }
    curr->next=prev;
    return reverseRecur(curr,agla,agla->next);
}
List* reverseRec(List *start)
{
    if(start==NULL || start->next==NULL)
    {
        return start;
    }
    node *smallhead = reverseRec(start->next);
    node *c = start;
    c->next->next = c;
    c->next= NULL;
    return smallhead;
}
List* middle(List *start )
{
    List *t1=start,*t2=start;
    while(t2!=NULL&&t2->next!=NULL)
    {
        t1=t1->next;
        t2=(t2->next)->next;
    }
    return t1;
}
void disp(List *start)
{
    if(start==NULL){
        cout<<"List is empty";
        return ;
    }
    List *curr = start;
    while(curr->next!=NULL){
        cout<<curr->data<<"->";
        curr=curr->next;
    }
    cout<<curr->data;
}
List* insertafter(List *start)
{
    List *temp=new List();
    temp->data=0;
    temp->next=NULL;
    cout<<"Enter the value: ";
    cin>>temp->data;
    cout<<"Enter the number you want to insert after:\n";
    int key;
    cin>>key;
    List *curr=start;
    List *prev=NULL;
    while(curr->data!=key&&curr->next!=NULL)
    {
        curr=curr->next;
    }
    temp->next=curr->next;
    curr->next=temp;
    return start;

}
List* insertbefore(List *start)
{

    List *temp=new List();
    temp->data=0;
    temp->next=NULL;
    cout<<"Enter the value you want to insert: ";
    cin>>temp->data;
    cout<<"Enter the number you want to insert before:\n";
    int key;
    cin>>key;
    List *curr=start;
    List *prev=NULL;
    if(start->data==key)
    {
        temp->next=start;
        start=temp;
        return start;
    }
    while(curr->data!=key && curr!=NULL)
    {
        prev=curr;
        curr=curr->next;
    }

    prev->next=temp;
    temp->next=curr;
    return start;
}
List* addsorted(List *start)
{
     List *temp=new List();
    temp->data=0;
    temp->next=NULL;
    cout<<"Enter the value: ";
    cin>>temp->data;
    if((start->data)>temp->data){
        temp->next=start;
        start=temp;
        return start;

    }
    List *curr = start;
    List *t;
    while(curr->data<temp->data && curr!=NULL)
    {
        t=curr;
        curr=curr->next;
    }
    t->next=temp;
    temp->next=curr;
    return start;


}
List* deleteparticular(List *start)
{
    cout<<"Enter the element you want to delete:\n";
    int ele;
    cin>>ele;
    List *curr=start;
    if(start->data==ele)
    {
        delete(start);
        start=start->next;
        return start;
    }
    while((curr->next)->data!=ele && curr->next!=NULL)
    {
        curr=curr->next;
    }
    if(curr->next==NULL)
    {
        cout<<"The number is not found and thus cannot be deleted";
        return start;
    }
    if((curr->next)->data==ele)
        {
            List *temp=curr->next;

            curr->next=temp->next;
            delete(temp);
            return start;
        }

}
List* deletefront(List *start)
{
    if(start==NULL){
            cout<<"Empty List";
        return start;
    }
    List *t=start;
    start=start->next;
    delete(t);
    return start;
}
List* rever(List* start)
{
    if(start==NULL || start->next==NULL)
    {
        return start;
    }
    List *prev=NULL;
    List *pres=start;
    List *agla=pres->next;

    while(agla!=NULL){


        pres->next=prev;

        prev=pres;

        pres=agla;

        agla=agla->next;

    }
    pres->next=prev;
    start=pres;
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
        cout<<"List is now empty";
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
List* addfront(List *start)
{

    List *temp=new List();
    temp->data=0;
    temp->next=NULL;
    cout<<"Enter the value: ";
    cin>>temp->data;
    if(start==NULL){
            start=temp;
    return start;

    }
    temp->next=start;
    start=temp;
    return start;
}
List* addrear(List *start)
{
    List *temp=new List;
    temp->data=0;
    temp->next=NULL;
    cout<<"Enter the value: ";
    cin>>temp->data;
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
List* sortlist(List *start)
{
    if(start==NULL||start->next==NULL)
{
    return start;

}
List *t1=NULL;
List *t2=NULL;
List *small=NULL;
for(t1=start;(t1->next)!=NULL;t1=t1->next)
{
    small=t1;
    for(t2=t1->next;t2!=NULL;t2=t2->next)
    {
        if(small->data>t2->data)
        {
            small=t2;
        }
    }
    int temp=t1->data;
    t1->data=small->data;
    small->data=temp;


}
return start;


}
List* deletealternate(List *start)
{
    if(start==NULL){
        cout<<"Empty List";
        return NULL;
    }
    if(start->next==NULL)
    {
        return start;
    }
    List *t1=start;
    List *t2=t1->next;
    while(t1!=NULL && t2!=NULL)
    {
        t2=t1->next;
        t1->next=t2->next;
        delete(t2);
        t1=t1->next;
    }
    return start;
}
void display(List *start)
{
    if(start==NULL){
        cout<<"Empty";
        return;
    }
    List *curr=start;
    cout<<"\n";
    while(curr->next!=NULL)
    {
        cout<<curr->data<<"  ->  ";
        curr=curr->next;
    }
    cout<<curr->data;
    cout<<"\n";
}


List* revers(List *start)
{
    if(start==NULL || start->next==NULL)
    {
        return start;
    }
    List *prev=NULL;
    List *pres=start;
    List *agla=pres->next;
    while(pres!=NULL)
    {
        pres->next=prev;
        prev=pres;
        pres=agla;
        if(agla==NULL)
        {
            break;
        }
        agla=agla->next;

    }
    start=prev;
    return start;


}
int main()
{
    List *start=NULL;
    start=addrear(start);
    start=addrear(start);
    start=addrear(start);
    start=addrear(start);
    start=addrear(start);
    cout<<"Current\n";
    display(start);
    cout<<"Reversed\n";
    start=reverseRecur(NULL,start,start->next);
    display(start);
    cout<<start->data;


}
