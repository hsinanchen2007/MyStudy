### 解题思路
此处撰写解题思路

### 代码

```c
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** levelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes){
typedef struct Queue{
    struct TreeNode*node;
    int layer;
}Queue;
Queue*queue=(Queue*)malloc(sizeof(Queue)*10000);
struct TreeNode*p;
int front,rear,i=0,j=0,k=0;
if(!root){
    *returnSize=0;
    return NULL;
}
int**ret=(int**)malloc(sizeof(int*)*10000);
ret[i]=(int*)malloc(sizeof(int)*10000);
front=rear=-1;
rear++;
queue[rear].node=root;
queue[rear].layer=1;
while(front!=rear){
    front++;
    p=queue[front].node;
    if(p->left!=NULL){
        rear++;
        queue[rear].node=p->left;
        queue[rear].layer=queue[front].layer+1;
    }
    if(p->right!=NULL){
        rear++;
        queue[rear].node=p->right;
        queue[rear].layer=queue[front].layer+1;
    }
}
*returnColumnSizes=(int*)malloc(sizeof(int)*1000);
front=queue[k].layer;
for(k=0;k<=rear;k++){
    if(queue[k].layer==front){
        ret[i][j++]=queue[k].node->val;
    }
    else{
        front=queue[k].layer;
        returnColumnSizes[0][i]=j;
        i++;j=0;
        ret[i]=(int*)malloc(sizeof(int)*10000);
        ret[i][j++]=queue[k].node->val;
    }
}
returnColumnSizes[0][i]=j;
*returnSize=i+1;
return ret;
}
```