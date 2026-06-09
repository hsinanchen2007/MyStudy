C 语言实现

```C []
int sumOfLeftLeaves(struct TreeNode* root) {
    if (!root) return 0;
    if (root->left && !root->left->left && !root->left->right)
        return root->left->val + sumOfLeftLeaves(root->right);
    else
        return sumOfLeftLeaves(root->left) + sumOfLeftLeaves(root->right);
}
```