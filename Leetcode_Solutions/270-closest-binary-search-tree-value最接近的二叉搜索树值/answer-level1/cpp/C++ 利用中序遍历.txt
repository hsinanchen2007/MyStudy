```cpp
int closestValue(TreeNode* root, double target) {
  stack<TreeNode*> s;
  TreeNode* pre = NULL;
  int res = root->val;
  while (root || !s.empty()) {
    if (root) {
      s.push(root);
      root = root->left;
    } else {
      root = s.top();
      s.pop();

      if (double(root->val) >= target) break;
      pre = root;
      root = root->right;
    }
  }
  if (!root) return pre->val;
  if (!pre) return root->val;
  return (pre->val + root->val < 2 * target) ? root->val : pre->val;
}
```
