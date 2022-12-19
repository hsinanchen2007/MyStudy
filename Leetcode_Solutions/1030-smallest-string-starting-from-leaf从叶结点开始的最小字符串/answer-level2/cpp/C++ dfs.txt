```cpp
void dfs(map<string, int>& M, string s, TreeNode* root) {
  if (!root) return;
  s += root->val + 'a';
  if (!root->left && !root->right) {
    reverse(s.begin(), s.end());
    M[s]++;
  }
  dfs(M, s, root->left);
  dfs(M, s, root->right);
}
string smallestFromLeaf(TreeNode* root) {
  map<string, int> M;
  dfs(M, {}, root);
  return M.begin()->first;
}
```
