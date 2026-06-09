```c++
int maxPath;
int maxPathSum(TreeNode* root) {
    maxPath = INT_MIN;
    maxPathSumR(root);
    return maxPath;
}
int maxPathSumR(TreeNode *root) {
    if (root == nullptr) return 0;
    int left = maxPathSumR(root->left);
    int right = maxPathSumR(root->right);
    maxPath = max(maxPath, left + right + root->val);
    maxPath = max(maxPath, left + root->val);
    maxPath = max(maxPath, right + root->val);
    maxPath = max(maxPath, root->val);
    int res = max(left, right) + root->val;
    return max(res, root->val);
}
```

在后序遍历的时候维护一个`maxPath`变量，而`maxPathSumR`中返回值则表示如果一定要包含`root`节点时的最大路径和。
