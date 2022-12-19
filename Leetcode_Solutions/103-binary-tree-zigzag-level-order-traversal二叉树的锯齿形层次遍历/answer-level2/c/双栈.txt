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
int** zigzagLevelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes){
    if(root==NULL){
        *returnSize=0;
        return NULL;
    }
    struct TreeNode *s1[10000],*s2[10000],*p;
    int **ret,i=0,j=0,top1=0,top2=0;
    ret=(int**)malloc(sizeof(int*)*1000);
    ret[i]=(int*)malloc(sizeof(int)*10000);
    returnColumnSizes[0]=(int*)malloc(sizeof(int)*1000);
    s1[top1++]=root;
    while(top1!=top2){
        while(top1!=0){
            p=s1[--top1];
            ret[i][j++]=p->val;
            if(p->left) s2[top2++]=p->left;
            if(p->right) s2[top2++]=p->right;
        }
        returnColumnSizes[0][i]=j;
        i++;
        if(top2==top1) break;
        j=0;
        ret[i]=(int*)malloc(sizeof(int)*10000);
        while(top2!=0){
            p=s2[--top2];
            ret[i][j++]=p->val;
            if(p->right) s1[top1++]=p->right;
            if(p->left) s1[top1++]=p->left;
        }
        returnColumnSizes[0][i]=j;
        i++;
        if(top2==top1) break;
        j=0;
        ret[i]=(int*)malloc(sizeof(int)*10000);
    }
    *returnSize=i;
    return ret;
}
```