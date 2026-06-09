计算子树元素和，应该自底向上，故考虑后序遍历，遍历过程中存取每个节点为根节点的子树元素和
```cpp
int dfs(unordered_map<int, int>& M, TreeNode* root) {
  if (!root) return 0;
  int left = dfs(M, root->left);
  int right = dfs(M, root->right);
  int sum = left + right + root->val;
  M[sum]++;
  return sum;
}
vector<int> findFrequentTreeSum(TreeNode* root) {
  if (!root) return {};
  vector<int> res;
  unordered_map<int, int> M;
  dfs(M, root);
  int maxTime = 0;
  for (auto item : M) maxTime = max(maxTime, item.second);
  for (auto item : M)
    if (item.second == maxTime) res.push_back(item.first);
  return res;
}
```
