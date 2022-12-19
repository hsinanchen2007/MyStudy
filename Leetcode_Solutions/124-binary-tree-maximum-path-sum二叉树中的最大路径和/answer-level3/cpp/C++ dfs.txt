/思路1： 内层后续，外层后续，leetcode耗时：1100ms

```cpp
// dfs返回从根出发的最大路径和
int dfs(TreeNode* root) {
  if (!root) return 0;
  int l = dfs(root->left);
  int r = dfs(root->right);
  return max(max(l, r) + root->val, root->val);
}
int maxPathSum(TreeNode* root) {
  if (!root) return INT32_MIN;
  int lr = max(maxPathSum(root->left), maxPathSum(root->right));
  int l = dfs(root->left);
  int r = dfs(root->right);
  int m = (l > 0 ? l : 0) + (r > 0 ? r : 0) + root->val;
  return max(lr, m);
}
```


/思路2：内层前序遍历 + 外层后序遍历 leetcode耗时：800ms:
```cpp
// dfs返回从根出发的最大路径和
void dfs(int& maxSum, int cur, TreeNode* root) {
  if (!root) return;
  cur += root->val;
  maxSum = max(maxSum, cur);
  dfs(maxSum, cur, root->left);
  dfs(maxSum, cur, root->right);
}
int maxPathSum(TreeNode* root) {
  if (!root) return INT32_MIN;
  int lmax = INT32_MIN, rmax = INT32_MIN;
  dfs(lmax, 0, root->left);
  dfs(rmax, 0, root->right);
  int m = (lmax > 0 ? lmax : 0) + (rmax > 0 ? rmax : 0) + root->val;
  int lr = max(maxPathSum(root->left), maxPathSum(root->right));
  return max(m, lr);
}
```


思路3： 一般双层都可优化为单层 耗时：40ms
```cpp
// dfs返回从根出发的最大路径和
// 同时计算经过该节点的最大路径和，用全局变量res维护求得的最大值
int dfs(int& res, TreeNode* root) {
  if (!root) return 0;
  int left_max = dfs(res, root->left);
  int right_max = dfs(res, root->right);
  int mid_max = (left_max > 0 ? left_max : 0) +
                (right_max > 0 ? right_max : 0) + root->val;
  res = max(res, mid_max);
  return max(max(left_max, right_max) + root->val, root->val);
}
int maxPathSum(TreeNode* root) {
  int res = INT32_MIN;
  dfs(res, root);
  return res;
}
```
