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


int countNodes(struct TreeNode* root){
    if(root==NULL) return 0;
    if(!root->left&&!root->right) return 1;
    return 1+countNodes(root->left)+countNodes(root->right);
}
```