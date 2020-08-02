#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};
typedef struct node *BTREE;

BTREE new_node(int data){
    BTREE p=(BTREE)malloc(sizeof(struct node));
    p->data=data;
    p->left=p->right=NULL;
    return p;
}

BTREE insert(BTREE root, int x){
    if (root == NULL)
    {
        root=new_node(x);
    }
    else
    {
        if (x<root->data)
        {
            root->left=insert(root->left,x);
        }
        else
        {
            root->right=insert(root->right,x);
        }
    }
    return root;
}

void inorder(BTREE root){
    if (root!=NULL)
    {
        inorder(root->left);
        printf("%d\t",root->data);
        inorder(root->right);
    }
}

int size(BTREE root){
    if (root!=NULL)
    {
        return 0;
    }
    else
    {
        return 1+size(root->left)+size(root->right);
    }
}

int leaves(BTREE root){
    if(root!=NULL){
        if (root->left==root->right)
        {
            return 1;
        }
        else
        {
            return leaves(root->left)+leaves(root->right);
        }
    }
    else
        return 0;
}

int height(BTREE root){
    if (root==NULL)
    {
        return -1;
    }
    else
    {
        int lHeight, rHeight;
        lHeight=height(root->left);
        rHeight=height(root->right);
        if (rHeight>lHeight)
        {
            return rHeight+1;
        }
        else
        {
            return lHeight+1;
        }
    }
}

main()
{
    BTREE myroot = NULL;
    int i;
    scanf("%d", &i);
    while (i!=-1)
    {
        myroot = insert(myroot,i);
        scanf("%d",&i);
    }
    inorder(myroot);
    printf("\nThe number of nodes is %d", size(myroot));
    printf("\nThe number of leaves is %d", leaves(myroot));
    printf("\nThe height of the tree is %d", height(myroot));
}
