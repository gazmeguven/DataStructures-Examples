#include<stdio.h>
#include<stdlib.h>
#define QUEUE_SIZE 5

struct node{
    int data;
    struct node *next;
}

typedef struct{
    int cnt;
    struct node *front;
    struct node *rear;
}queue;

int isfull(queue *q){
    if (q->cnt==QUEUE_SIZE)
    {
        return 1;
    }
    else
    {
        return 0;
    }   
}

int isempty(queue *q){
    if (q->cnt==0)
    {
        return 1;
    }
    else
    {
        return 0;
    }   
}

void initialize(queue *q){
    q->cnt=0;
    q->rear=q->front=NULL;
}

void enqueue(queue *q, int x){
    if (isfull(q))
    {
        printf("Queue is full");
    }
    else
    {
        struct node *temp=(struct node *)malloc(sizeof(struct node));
        temp->data=x;
        temp->next=NULL;
        if(isempty(q)){
            q->rear=q->front=temp;
        }
        else
        {
            q->rear->next=temp;
            q->rear=temp;
        }
        q->cnt++;
    }
}

int dequeue(queue *q){
    if (isempty(q))
    {
        printf("Queue is empty");
        return -100;
    }
    else
    {
        struct node *temp=q->front;
        int x=temp->data;
        q->front=temp->next;
        free(temp);
        q->cnt--;
        return x;
    }
}

main(){
    queue q;
    initialize(&q);
    enqueue("&q",10);
    enqueue("&q",4);
    enqueue("&q",8);
    enqueue("&q",9);
    enqueue("&q",12);
    enqueue("&q",12);
    printf("\n%d", dequeue(&q));
    printf("\n%d", dequeue(&q));
    printf("\n%d", dequeue(&q));
    printf("\n%d", dequeue(&q));
    printf("\n%d", dequeue(&q));
}