#include<bits/stdc++.h>
using namespace std;
class List
{
    public:
    int data;
    List *next;
};

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
List* kReverse(List *start,int k)
{
    List *prev=NULL;
    List *ptr1=NULL,*pptr=NULL;
    List *curr=start;
    List *agla=NULL;
    int coun=0,startcount=0;
    while(curr!=NULL)
    {
        agla=curr->next;
        if(coun==0)
        {
            pptr=ptr1;
            ptr1=curr;
        }
        else if(coun==(k-1) && startcount!=(k-1))
        {
            ptr1->next=curr->next;
        }
        else if(coun==(k-1) && startcount==(k-1))
        {
            start=curr;
            ptr1->next=curr->next;
        }
        curr->next=prev;
        if(coun==(k-1))
        {
            if(pptr!=NULL)
            {
                pptr->next=curr;
            }
            prev=ptr1;
            curr=agla;
            coun=0;

        }
        else{
            prev=curr;
            curr=agla;
            coun++;
        }
        startcount++;
    }
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


int main()
{
    List *start=NULL;
    int n;
    cin>>n;
    int k;
    cin>>k;
    for(int i=0;i<n;i++)
    {
        int data;
        cin>>data;
        start=addrear(start,data);
    }
    //display(start);
    //cout<<"\n";
    if(n==k)
    {
        start=revers(start);
    }
    else if(k==1)
    {
        display(start);
        exit(0);
    }
    else{
        start=kReverse(start,k);
    }
    //start=kReverse(start,k);
    display(start);
}
