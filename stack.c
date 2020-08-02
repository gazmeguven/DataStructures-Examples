#include<stdio.h>
#include<stdlib.h>
#define STACK_SIZE 5

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

main()
{
    stack s;
    reset(&s);
    char exp[20], *e;
    int n1,n2,num;
    printf("Enter postfix expression:");
    scanf("%s",exp);
    e=exp;
    while (*e!='\0')
    {
        if (isdigit(*e))
        {
            num=*e-48;
            push(&s,num);
        }
        else
        {
            n1=pop(&s);
            n2=pop(&s);

            switch (*e)
            {
            case '+':
                push(&s,n1+n2);
                break;
            case '-':
                push(&s,n2-n1);
                break;
            case '*':
                push(&s,n1*n2);
                break;
            case '/':
                push(&s,n1/n2);
                break;
            default:
                break;
            }
        }
        e++;
    }
    printf("\nThe result is %d", pop(&s));
}