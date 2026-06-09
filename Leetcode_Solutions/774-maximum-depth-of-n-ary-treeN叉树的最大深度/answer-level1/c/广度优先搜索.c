纯c手写队列，加上bfs
```
/**
 * Definition for a Node.
 * struct Node {
 *     int val;
 *     int numChildren;
 *     struct Node** children;
 * };
 */
 typedef struct Node node;
typedef struct
{
    node *data[100000];
    int rear;
    int front;
}cqueue;
cqueue num;
cqueue*numm=&num;
node *temp;
node *goal;
int isempty(cqueue*a)
{
    if(a->rear==a->front)
    {
        return 1;
    }
    return 0;
}
void empty(cqueue*a)
{
    a->rear=a->front=-1;
}
void push(cqueue*a,node *x)
{
    a->rear++;
    a->data[a->rear]=x;
}
void pop(cqueue*a)
{
    a->front++;
}
int* maxDepth(struct Node* root) {
    int i;
    if(root==NULL)
    {
        return 0;
    }
    root->val=1;
    push(numm,root);
    while(!isempty(numm))
    {
        temp=numm->data[numm->front+1];
        pop(numm);
        for(i=0;i<temp->numChildren;i++)
        {
            if(temp->children[i]!=NULL)
            {
                temp->children[i]->val=temp->val+1;
                push(numm,temp->children[i]);
            }
        }
    }
    return temp->val;
}
```
