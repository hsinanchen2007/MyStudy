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


int maxDepth(struct TreeNode* root)
{
    if(root==NULL)
      return 0;
    int m=1,n=1;
    if(root->left!=NULL)
      m+=maxDepth(root->left);
    if(root->right!=NULL)
      n+=maxDepth(root->right);
    return (m>=n)?m:n;

}
```