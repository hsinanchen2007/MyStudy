### 解题思路
递归二叉树

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


struct TreeNode* invertTree(struct TreeNode* root){
    if(root==0)
        return 0;
    struct TreeNode* left=invertTree(root->left);
    struct TreeNode* right=invertTree(root->right);
    root->left=right;
    root->right=left;
    return root;
}
```