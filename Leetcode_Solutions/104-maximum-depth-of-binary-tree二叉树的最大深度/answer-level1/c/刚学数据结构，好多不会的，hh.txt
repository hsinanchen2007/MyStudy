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


int maxDepth(struct TreeNode* root){
    int left_depth,right_depth,max;
    if(root==NULL)
        return 0;
    if(root->left==NULL&&root->right==NULL)
        return 1;
    left_depth=maxDepth(root->left);
    right_depth=maxDepth(root->right);
    max=left_depth>right_depth?left_depth:right_depth;
    return 1+max;
}
```