//SINGLY LINKED LIST:
#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;

typedef struct node
{
    int data;
    node *next;
};

int Link_len(node* n)
{
    int i=0;
    while(n!=NULL)
    {
        n = n->next;
        i++;
    }
    return i;
}

node* Create_Node()
{
    node* n;
    n = (node*)malloc(sizeof(node));
    return n;
}

void Store_Data(node* n)
{
    printf("Enter Data : ");
    scanf("%d",&n->data);
}

node* insertF(node* n,int k)
{
    node *t = Create_Node();
    t->data = k;
    t->next = n;
    return t;
}

void insertL(node* n,int k)
{
    node *t = Create_Node();
    t->data = k;
    while(n->next!=NULL)
    {
        n = n->next;
    }
    n->next = t;
    t->next = NULL;
}

void insertP(node* l,int p,int k)
{
    int i=0;
    node* t = Create_Node();
    t->data = k;
    while(i<p-2)
    {
        l = l->next;
        i++;
    }
    t->next = l->next->next;
    l->next  = t;

}

node* deleteF(node* l)
{
    node* t;
    t = l->next;
    free(l);
    return t;
}

void deleteL(node* l)
{
    while(l->next->next !=NULL)
    {
        l = l->next;
    }
    l->next =NULL;
    free(l->next);
}

void deleteP(node* l,int p)
{
    int i=0;
    node *t;
    while(i<p-2)
    {
        l = l->next;
        i++;
    }
    t = l->next;
    l->next = l->next->next;
    free(t);
}
node* Create_LinkL(int n)
{
    int i=0;
    node *t,*m;
    t = Create_Node();
    Store_Data(t);
    printf("%");
    m = t;
    for(i=0;i<n-1;i++)
    {
        t->next = Create_Node();
        Store_Data(t->next);
        t = t->next;
    }
    t->next = NULL;
    return m;
}

void Print_LinkL(node* t)
{
    printf("\n");
    while(t!=NULL)
    {
        printf("%d ",t->data);
        t = t->next;
    }
    printf("\n");
}

int main()
{
int com=1,k,p;
node* link = Create_LinkL(5); // create linked list.
printf("\n 0 -Quit\n 1 -Insert First\n 2 -Insert Last\n 3 -Insert position\n 4 -Delete first\n 5 -Delete Last\n 6 -Delete position\n");
while(1)
{
    if(com ==0)
        exit(0);
    printf("Enter Command: ");
    scanf("%d",&com);
    if(com ==1 )    
    { 
        printf("Enter the element: ");
        scanf("%d",&k);
        link = insertF(link,k);
    }
    else if(com ==2 )
    { 
        printf("Enter the element: ");
        scanf("%d",&k);
        insertL(link,k);
    }
    else if(com ==3 )
    { 
        printf("Enter the element: ");
        scanf("%d",&k);
        printf("Enter Position: ");
        scanf("%d",&p);
        insertP(link,p,k);
    }
    else if(com ==4 )
    { 
        link = deleteF(link);
    }
    else if(com ==5 )
    { 
        deleteL(link);
    }
    else if(com ==6 )
    { 
        printf("Enter Position: ");
        scanf("%d",&p);
        deleteP(link,p);
    }
Print_LinkL(link);
}
}