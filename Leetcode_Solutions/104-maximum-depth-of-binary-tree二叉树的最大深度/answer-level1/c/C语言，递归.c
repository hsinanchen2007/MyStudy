### 解题思路
递归，常规解法

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

    if(root==NULL)return 0;
    if(root->left==NULL&&root->right==NULL)return 1;
    int right=maxDepth(root->right)+1;
    int left=maxDepth(root->left)+1;
    return (right>left?right:left);
}
```