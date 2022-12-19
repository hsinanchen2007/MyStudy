### 解题思路
1. 递归
2. 检查左子树的左节点是否等于右子树右节点，左子树的右节点是否等于右子树左节点

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

bool isMirror(struct TreeNode* left, struct TreeNode* right)
{
    if (left == NULL && right == NULL) return true;
    if (left == NULL || right == NULL) return false;
    if (left->val == right->val)
    {
        return isMirror(left->left, right->right) && isMirror(left->right, right->left);
    }
    else return false;
}

bool isSymmetric(struct TreeNode* root){
    if (root == NULL) return true;
    else return isMirror(root->left, root->right);
}
```