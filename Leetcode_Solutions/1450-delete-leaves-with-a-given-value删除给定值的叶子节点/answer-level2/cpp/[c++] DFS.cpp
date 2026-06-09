**四行代码,感觉写完就像一个艺术品**
```
TreeNode *removeLeafNodes(TreeNode *root, int target) {
    if (root == nullptr) return nullptr;
    root->left = removeLeafNodes(root->left, target);
    root->right = removeLeafNodes(root->right, target);
    return root->left == nullptr && root->right == nullptr && root->val == target ? nullptr : root;
}
```
