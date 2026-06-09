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
int** levelOrderBottom(struct TreeNode* root, int* returnSize, int** returnColumnSizes){
	if(root==NULL){
        *returnSize=0;
        return NULL;
    }
    struct TreeNode *queue[10000],*p;
    int **ret,i=0,j=0,front=0,rear=0,last,*t,temp;
    ret=(int**)malloc(sizeof(int*)*1000);
    ret[i]=(int*)malloc(sizeof(int)*10000);
    returnColumnSizes[0]=(int*)malloc(sizeof(int)*1000);
    queue[rear++]=root;
    last=rear;
    while(front!=rear){
        p=queue[front++];
        ret[i][j++]=p->val;
        if(p->left)  queue[rear++]=p->left;
        if(p->right) queue[rear++]=p->right;
        if(last==front){
            last=rear;
            returnColumnSizes[0][i]=j;
            i++;
            j=0;
            ret[i]=(int*)malloc(sizeof(int)*10000);
        }
    }
    *returnSize=i;
    i--;
    j=0;
    while(j<i){
        t=ret[i];
        temp=returnColumnSizes[0][i];
        ret[i]=ret[j];
        returnColumnSizes[0][i]=returnColumnSizes[0][j];
        ret[j]=t;
        returnColumnSizes[0][j]=temp;
        i--;
        j++;
    }
    return ret;
}
```