### 解题思路
递归

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
    if(root==0)return 0;
    int leftHeight=maxDepth(root->left);
    int rightHeight=maxDepth(root->right);
    int height=leftHeight>rightHeight?leftHeight+1:rightHeight+1;
    return height;
}
```