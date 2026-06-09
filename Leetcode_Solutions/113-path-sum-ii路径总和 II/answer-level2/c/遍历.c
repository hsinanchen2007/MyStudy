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
void dfs(struct TreeNode* root, int sum, int* returnSize, int** returnColumnSizes,int a,int i,int *buf,int **ret){
    if(root==NULL) return ;
    else if(!root->left&&!root->right&&sum==a+root->val){
        buf[i++]=root->val;
        returnColumnSizes[0][*returnSize]=i;
        //printf("%d  ",*returnSize);
        ret[*returnSize]=(int*)malloc(sizeof(int)*10000);
        for(int j=0;j<i;j++) ret[*returnSize][j]=buf[j];
        (*returnSize)++;
    }
    else{
        buf[i++]=root->val;
        a+=root->val;
        if(root->left) dfs(root->left,sum,returnSize,returnColumnSizes,a,i,buf,ret);
        if(root->right) dfs(root->right,sum,returnSize,returnColumnSizes,a,i,buf,ret);
    }
}
int** pathSum(struct TreeNode* root, int sum, int* returnSize, int** returnColumnSizes){
    int **ret,*buf;
    ret=(int**)malloc(sizeof(int*)*1000);
    returnColumnSizes[0]=(int*)malloc(sizeof(int)*1000);
    buf=(int*)malloc(sizeof(int)*10000);
    *returnSize=0;
    dfs(root,sum,returnSize,returnColumnSizes,0,0,buf,ret);
    return ret;
}
```