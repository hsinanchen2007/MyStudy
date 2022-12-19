### 解题思路
击败了98.95%的用户

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
    if (root == NULL) return false;
    sum -= root->val;
    if (root->left == NULL && root->right == NULL) return (sum == 0);
    return hasPathSum(root->left, sum) || hasPathSum(root->right, sum);
}
```