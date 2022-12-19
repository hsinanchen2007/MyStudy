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
 * Note: The returned array must be malloced, assume caller calls free().
 */
void pre(struct TreeNode* root, int* returnSize,int *ret){
    if(root->left) pre(root->left,returnSize,ret);
    if(root->right) pre(root->right,returnSize,ret);
    ret[(*returnSize)++]=root->val;
}
int* postorderTraversal(struct TreeNode* root, int* returnSize){
    if(root==NULL){
        *returnSize=0;
        return NULL;
    }
    int *ret;
    *returnSize=0;
    ret=(int*)malloc(sizeof(int)*1000);
    pre(root,returnSize,ret);
    return ret;
}
```