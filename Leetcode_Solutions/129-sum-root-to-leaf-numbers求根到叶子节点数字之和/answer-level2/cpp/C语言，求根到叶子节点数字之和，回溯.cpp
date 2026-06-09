思路：回溯

1. 变更状态：路径和按 十进制 左移，并将 val 添加至个位
2. 操作/递归：当节点为叶子节点，则将路径和 path 添加到 res，否则递归进入左右子树
3. 恢复状态：路径和按 十进制 右移

```C
void backtrack(struct TreeNode* root, int* res, int path) {
    if (!root) return;
    path = path * 10 + root->val;                   // 1. 变更状态
    if (!root->left && !root->right) *res += path;  // 2. 操作/递归
    else backtrack(root->left, res, path), backtrack(root->right, res, path);
    path = path / 10;                               // 3. 恢复状态
}
int sumNumbers(struct TreeNode* root){
    int res = 0;
    backtrack(root, &res, 0);
    return res;
}
```