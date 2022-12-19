- 执行用时 :8 ms, 在所有 C 提交中击败了86.15%的用户
- 内存消耗 :7.7 MB, 在所有 C 提交中击败了100.00%的用户

```
int sumOfLeftLeaves(struct TreeNode* root) {
    if (root == NULL) return 0;
    return leaf_num(root, 1);//由于当只有一个节点时，判定为没有左叶子节点
}
int leaf_num(struct TreeNode* root, int node) {
    int n = 0;
    if (root->left  != NULL)                                    n += leaf_num(root->left, 0);
    if (root->right != NULL)                                    n += leaf_num(root->right, 1);
    if (!node && (root->left == NULL) && (root->right == NULL)) return root->val;
    return n;
}
```
