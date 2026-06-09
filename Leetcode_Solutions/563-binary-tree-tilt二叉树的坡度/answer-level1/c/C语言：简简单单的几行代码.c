- 执行用时 :6 ms, 在所有 C 提交中击败了100.00%的用户
- 内存消耗 :5 MB, 在所有 C 提交中击败了100.00%的用户
递归遍历，不断相加

```
int NODE_SUMS[10240] = {0};
int NODE_NUMBER = 0;
int findTilt(struct TreeNode* root){
    NODE_NUMBER = 0;
    for (int i = 0; i < 1024; ++i) NODE_SUMS[i] = 0;

    node_dfs(root);
    int sum = 0;

    for (int i = 0; i < NODE_NUMBER; i++) {
        sum += NODE_SUMS[i];
    }
    return sum;
}

int node_dfs(struct TreeNode* root)
{
    if (root == NULL) return 0;
    int left_val = node_dfs(root->left);
    int right_val = node_dfs(root->right);

    int tmp = left_val - right_val;
    tmp = (tmp > 0 ? tmp : -tmp);
    NODE_SUMS[NODE_NUMBER++] = tmp;//装入缓冲栈中

    return root->val + left_val + right_val;
}
```
