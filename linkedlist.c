#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next
};

struct node *addfront(struct node *head, int key){
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data=key;
    temp->next=head;
    head=temp;
    return head;
};

struct node *addlast(struct node *head, int key){
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data=key;
    temp->next=NULL;
    if(head == NULL){
        head=temp;
    }
    else{
        struct node *last=head;
        while(last->next!=NULL){
            last=last->next;
        }
        last->next=temp;
    }
return head;
};

void print(struct node *head){
    if(head==NULL){
        printf("List is empty");
    }
    else{
        while(head!=NULL){
            printf("%d\t",head->data);
            head=head->next;
        }
    }
};

int count(struct node *head){
    int counter=0;
    while(head!=NULL){
        counter++;
        head=head->next;
    }
    return counter;
}

struct node *del(struct node *head, int key){
    if(head!=NULL){
        struct node *temp=head;
        if(head->data==key){
            head=head->next;
            free(temp);
        }
        else
        {
            while (temp->next!=NULL && temp->next->data!=key)
            {
                temp=temp->next;
            }
            if (temp->next=NULL)
            {
                printf("no key in the list\n");
                return head;
            }
            struct node *del=temp->next;
            temp->next=del->next;
            free(del);     
        }
    }
    return head;
}

struct node *destroy(struct node *head){
    struct node *temp=head;
    while (head!=NULL)
    {
        head=head->next;
        free(temp);
        temp=head;
    }
    return head;
}

main(){
    struct node *head = NULL;
    head=addfront(head, 10);
    head=addfront(head, 5);
    head=addlast(head, 8);
    head=addlast(head, 1);
    print(head);
    printf("\n");
    head=del(head,10);
    print(head);
    head = destroy(head);
    print(head);
}