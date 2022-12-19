### 解题思路
递归的解法

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


struct TreeNode* invertTree(struct TreeNode* root)
{
struct TreeNode*transfer=NULL;
if(root==NULL)return NULL;
if(root->left==NULL&&root->right==NULL)
return root;
transfer=invertTree(root->left);
root->left=invertTree(root->right);
root->right=transfer;
return root;
}
```