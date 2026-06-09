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


bool hasPathSum(struct TreeNode* root, int sum){
    if (root == 0)
      return 0;

    if ((root->left == 0) && (root->right == 0))
      return sum-root->val == 0?1:0;

    return hasPathSum(root->left, sum-root->val) || hasPathSum(root->right, sum-root->val);
}
```