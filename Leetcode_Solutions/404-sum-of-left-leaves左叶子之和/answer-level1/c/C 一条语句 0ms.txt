```
int sumOfLeftLeaves(struct TreeNode* root) {
    return root ? ((root->left && (!root->left->left) && (!root->left->right)) ? root->left->val : 0)
        + sumOfLeftLeaves(root->left) + sumOfLeftLeaves(root->right) : 0;
}
```
如代码所示