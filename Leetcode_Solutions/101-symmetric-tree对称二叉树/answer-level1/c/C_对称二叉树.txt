### 解题思路


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

bool isSymmetric(struct TreeNode* root){
    if (root == NULL) return true;
    return fun(root->left, root->right);
}

int fun(struct TreeNode* l_root, struct TreeNode* r_root)
{
    if (l_root == NULL && r_root == NULL) return true;
    if (l_root == NULL || r_root == NULL) return false;

    return    (l_root->val == r_root->val)   &&
           fun(l_root->left,  r_root->right) &&
           fun(l_root->right, r_root->left);
}
```