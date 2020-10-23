#include<iostream>

using namespace std;

struct node
{
    int val;
    struct node *next;
}*start,*n,*c,*p,*temp;

struct node* newnode()
{
    struct node *nw=new node;
    cout<<"\nEnter value for node:";
    cin>>nw->val;
    nw->next=NULL;
    return nw;
}

void rev_link()
{
 c=n=start;
 p=NULL;
 while(n!=NULL)
 {
     n=n->next;
     c->next=p;
     p=c;
     c=n;
 }
 start=p;
}

int main()
{
    int no,x;
    cout<<"Enter no of nodes :";
    cin>>no;
    for(int i=1;i<=no;i++)
    {
        if(i==1)
        {
          start=newnode();
          temp=start;
        }
        else
        {
           temp->next=newnode();
           temp=temp->next;
        }
    }
    cout<<"\nLinked list :";
    temp=start;
    while(temp!=NULL)
     {
         cout<<temp->val<<"->";
         temp=temp->next;
     }
     cout<<"NULL";
    rev_link();
    cout<<"\nReversed linked list :";
    temp=start;
    while(temp!=NULL)
     {
         cout<<temp->val<<"->";
         temp=temp->next;
     }
     cout<<"NULL";
    return 0;
}
