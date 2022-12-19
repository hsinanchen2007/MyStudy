```cpp
vector<double> averageOfLevels(TreeNode* root) {
  if (!root) return {};
  vector<double> res;
  queue<TreeNode*> q;
  q.push(root);
  while (!q.empty()) {
    double sum = 0;
    int n = q.size();
    for (int i = 0; i < n; i++) {
      root = q.front();
      sum += root->val;
      q.pop();
      if (root->left) q.push(root->left);
      if (root->right) q.push(root->right);
    }
    res.push_back(sum / n);
  }
  return res;
}
```
