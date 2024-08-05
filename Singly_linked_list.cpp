#include <bits/stdc++.h>
using namespace std;


struct Node
{
    int data;
    Node *next;
};
void printList(Node *n)
{
    while (n!=NULL)
    {
        cout<<n->data<<" ";
        n=n->next;
    }
    
}

void Insert_at_begin(Node **head_ref,int newData)
{
    Node *newnode = new Node();
    newnode->next=*head_ref;    //*head_ref = head
    newnode->data=newData;

    *head_ref=newnode; 
}

void InsertAfter(Node *prev_node, int newData)
{
    Node *newnode = new Node();
    newnode->next=prev_node->next;
    prev_node->next=newnode;
    newnode->data=newData;
}

void Insert_at_end(Node **head_ref,int newData)
{
    Node *newnode = new Node();
    newnode->data=newData;
    newnode->next=NULL;

    if(*head_ref==NULL)     //if head is empty
    {
        *head_ref = newnode;
        return;
    }

    Node *last = *head_ref;
    while(last->next!=NULL) 
    {
        last=last->next;
    }
    last->next = newnode;
}

void delete_node(Node **head_ref ,int key)
{
    Node *prev , *temp;
    temp = *head_ref;

    if(temp!=NULL && temp->data == key)
    {
        *head_ref = temp->next;
        free(temp);
        return;
    }

    while(temp!=NULL && temp->data!=key)
    {
        prev = temp;
        temp = temp->next;
    }

    if(temp==NULL)  
    {
        cout<<"Key not found"<<endl;
    }

    prev->next = temp->next;
    free(temp);

}

int main()
{
    // new Node() - dyanamic memory allocation
    
    Node *head = new Node();
    Node *second = new Node();
    Node *third = new Node();

    head->data=1;
    head->next=second;

    second->data=2;
    second->next=third;

    third->data=3;
    third->next=NULL;

    Insert_at_begin(&head,0);
    InsertAfter(second,-2);
    Insert_at_end(&head,100);

    printList(head);

    cout<<""<<endl;

    delete_node(&head,-2);

    printList(head);

    return 0;
}