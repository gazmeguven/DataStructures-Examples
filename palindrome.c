#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define QUEUE_SIZE 50
#define STACK_SIZE 50

typedef struct{
    int data[STACK_SIZE];
    int top;
}stack;

void reset(stack *stk){
    stk->top=-1;
}

void push(stack *stk, int c){
    if (stk->top==STACK_SIZE-1)
    {
        printf("Stack is full\n");
    }
    else
    {
        stk->top++;
        stk->data[stk->top]=c;
    }
}

int pop(stack *stk){
    if (stk->top==-1)
    {
        printf("Stack is empty");
        return -100;
    }
    else
    {
        return stk->data[stk->top--];
    }
}

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

main()
{
    queue q;
    stack s;
    char str[100];
    initialize(&q);
    reset(&s);
    int i = 0;

    printf("Enter a string:");
    gets(str);

    while (i<strlen(str))
    {
        if ((str[i]>='a' && str[i]<='z') || (str[i]>='A' && str[i]<='Z') )
        {
            enqueue(&q, tolower(str[i]));
            push(&s, tolower(str[i]));
        }
        i++;
    }
    while (!isempty(&q))
    {
        if (pop(&s)!=dequeue(&q))
        {
            printf("It is not palindrome");
            exit(1);
        }
    }
    printf("It is palindrome");
}
