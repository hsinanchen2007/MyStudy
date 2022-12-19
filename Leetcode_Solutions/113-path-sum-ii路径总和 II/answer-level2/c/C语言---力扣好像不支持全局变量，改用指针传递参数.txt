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
bool DFS(struct TreeNode*root,int sum,int**result,int total,int nums,int**returnColumnSizes,int*ret,int*i)
{   
    if(root==NULL)
    return false;
    if((root->left==NULL)&&(root->right==NULL)){
        total=total+root->val;
        if(total==sum){
            ret[nums++]=root->val;
            result[(*i)]=(int*)malloc(sizeof(int)*(nums+1));
            for(int j=0;j<nums;j++)
            result[(*i)][j]=ret[j];       
            returnColumnSizes[0][(*i)++]=nums;
            return true;
        }
    }
    ret[nums++]=root->val;
    total=total+root->val;
    bool a=DFS(root->left,sum,result,total,nums,returnColumnSizes,ret,i);
    bool b=DFS(root->right,sum,result,total,nums,returnColumnSizes,ret,i);
    return a||b;
}
int** pathSum(struct TreeNode* root, int sum, int* returnSize, int** returnColumnSizes){
*returnSize=0;
int**result=(int**)malloc(sizeof(int*)*1000);
int i=0;
*returnColumnSizes=(int*)malloc(sizeof(int)*1000);
int total=0;
int nums=0;
int ret[1024]={0};
if(DFS(root,sum,result,total,nums,returnColumnSizes,ret,&i)){
    *returnSize=i;
    return result;
}
return 0;
}
```