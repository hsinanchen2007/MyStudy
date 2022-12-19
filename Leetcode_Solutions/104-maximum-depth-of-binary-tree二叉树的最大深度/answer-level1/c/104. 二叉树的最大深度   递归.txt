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
    int right,left;
    if(root ==NULL)
        return 0;
    if(root->left == NULL && root->right ==NULL)
        return 1;
    left = maxDepth(root->left);
    right = maxDepth(root->right);
    return (left > right ? left : right) + 1;
}
```