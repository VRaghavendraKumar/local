#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node* link;
};
struct node* create(int n)
{
    struct node* head=NULL;
    struct node* ptr=NULL;
    for(int i=0;i<n;i++)
    {
     struct node* newnode=malloc(sizeof(struct node));
     if(newnode==NULL)
     {
        printf("memory allocation failed\n");
        exit(1);
     }
    printf("\nenter the data of node %d ",i+1);
    scanf("%d",&newnode->data);
    if(head==NULL)
    {
        head=newnode;
        ptr=head;
    }
    else
    {
        ptr->link=newnode;
        ptr=newnode;
    }
    
    }
    ptr->link=NULL;
    return head;
}
void number(struct node *head)
{
    int count=0;
    if(head==NULL)
    {
        printf("list is empty broo");
    }
    struct node *ptr=NULL;
    ptr=head;
    while(ptr!=NULL)
    {
        count++;
        ptr=ptr->link;
    }
    printf("\nthe number of nodes are %d",count);
}
void display(struct node *head)
{
    if(head==NULL)
    {
        printf("\n node is empty");
        exit(1);
    }
    struct node *ptr=NULL;
    ptr=head;
    printf("\n the elements are");

     while(ptr!=NULL)
    {
    printf(" %d ",ptr->data);
    ptr=ptr->link;
    }
}
struct node* insertend(struct node *head,int a)
{
    struct node *newnode=malloc(sizeof(struct node));
    newnode->data=a;
    newnode->link=NULL;
    if(head==NULL)
    {
        head=newnode;
    }
    else
    {
    
    struct node *ptr=NULL;
    ptr=head;
    while(ptr->link!=NULL)
    {
        ptr=ptr->link;
    }
    ptr->link=newnode;
     printf("\nnode added at the end");
    }
    return head;
}
struct node* insertbeg(struct node *head,int a)
{
    struct node* newnode=malloc(sizeof(struct node));
    newnode->link=head;
    newnode->data=a;
    head=newnode;
    printf("\nnode inserted at the beginning");
    return head;
}
struct node* insertmiddle(struct node *head,int a,int p)
{
    struct node* newnode=malloc(sizeof(struct node));
    struct node* ptr=NULL;
    newnode->data=a;
    ptr=head;
    if(p==1)
    {
        newnode->link=head;
        head=newnode;
        return head;

    }
    for(int i=0;i<p-2;i++)
    {
        ptr=ptr->link;
    }
    newnode->link=ptr->link;
    ptr->link=newnode; 
    printf("\nnode inserted at middle") ;
    return head;
}
struct node* deletefirst(struct node *head)
{
    if(head==NULL)
    {
        printf("\nlist is empty broo");
        return head;
    }
    else
    {
        struct node*temp=head;
        head=head->link;
        free(temp);

    }
    printf("\n first node is deleted");
    return head;
}
struct node* deleteend(struct node *head)
{
    if(head==NULL)
    {
        printf("\n list is empty broo");
        return head;
    }
    else if(head->link==NULL)
    {
        free(head);
        head=NULL;
        printf("\n last node is first node and is deleted ");
        return head;
    }
    else
    {
        struct node *temp1=head;
        struct node *temp2=head;
        temp1=temp1->link;

        while(temp1->link!=NULL)
        {
            temp2=temp2->link;
            temp1=temp1->link;
        }
        temp2->link=NULL;
    
        free(temp1);
        printf("\nlast node deleted ");
        return head; 
    }
}
struct node* deletemiddle(struct node* head,int p)
{
    if(head==NULL)
    {
        printf("\n node is empty broo ");
        return head;
    }
    else if(p==1)
    {
         struct node *ptr1=head;
        head=head->link;
        free(ptr1);
         printf("\n node at %d is deleted ",p);
        ptr1=NULL;
        return head;
    }
    else
    {
        struct node *ptr1=head;
        struct node *ptr2=head;
         printf("\n node at %d is deleted ",p);
        while(p!=1)
        {
            ptr2=ptr1;
            ptr1=ptr1->link;
            p--;
        }
        ptr2->link=ptr1->link;
        free(ptr1);
        ptr1=NULL;
        return head;
    }
}
struct node* deleteall(struct node *head)
{
    if(head==NULL)
    {
        printf("\n its already empty broo ");
    }
    else
    {
        struct node *temp=head;
        while(temp!=NULL)
        {
            temp=temp->link;
            free(head);
            head=temp;
            printf("\n all nodes are deleted");
        }
        return head;

    }
}
struct node *reverse(struct node * head)
{
    struct node * temp=NULL;
    struct node * temp2=NULL;
    while(head!=NULL)
    {
    temp2=head->link;
    head->link=temp;
    temp=head;
    head=temp2;
    }
    head=temp;
    printf("\n successfully reversed ");
    return head;
}
struct node *insertsort(struct node *head,int a)
{
    struct node *newnode=malloc(sizeof(struct node));
    newnode->data=a;
    if(head==NULL||a<head->data)
    {
        newnode->link=head;
        head=newnode;
    }
    else
    {
    struct node *temp=head;
    while(temp->link!=NULL &&temp->link->data<a)
    {
        temp=temp->link;
    }
    
    newnode->link=temp->link;
    temp->link=newnode;
    return head;
    }
}

int main()
{
    struct node*head=NULL;
    head=create(1);
    head=insertsort(head,10);
    head=insertsort(head,6);
    head=insertsort(head,5);
    head=insertsort(head,4);
    head=insertsort(head,2);
     display(head);



    // head=insertend(head,40);
    // display(head);
    // head=insertbeg(head,60);
    // display(head);
    // number(head);
    // head=deletefirst(head);
    // display(head);
    // head=insertmiddle(head,110,1);
    // display(head);
    // head=deleteend(head);
    // display(head);
   // head=reverse(head);
    display(head);
}
   