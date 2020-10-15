#include<iostream>
using namespace std;
class List
{
    public:
    int data;
    List *next;
};

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

int lengthLL(List *start)
{
    List *curr = start;
    int len=0;
    while(curr!=NULL)
    {
        len++;
        curr=curr->next;
    }
    return len;
}
int main()
{
    List *start=NULL;
    int data;
    cin>>data;
    while(data!=-1)
    {
        start=addrear(start,data);
        cin>>data;
    }
    int k;
    cin>>k;
    int k1=lengthLL(start)-k;
    List *curr=start;
    for(int i=0;i<k1;i++)
    {
        curr=curr->next;
    }
    cout<<curr->data;

}
