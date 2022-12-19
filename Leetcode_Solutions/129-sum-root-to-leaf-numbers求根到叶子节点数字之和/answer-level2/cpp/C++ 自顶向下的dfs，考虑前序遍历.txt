```cpp
//* 思路：自顶向下的dfs，考虑前序遍历
void dfs(vector<int>& nums, int tmp, TreeNode* root) {
  if (!root) return;
  tmp = tmp * 10 + root->val;
  if (!root->left && !root->right) nums.push_back(tmp);
  dfs(nums, tmp, root->left);
  dfs(nums, tmp, root->right);
}
int sumNumbers(TreeNode* root) {
  vector<int> nums;
  dfs(nums, 0, root);
  return accumulate(nums.begin(), nums.end(), 0);
}
```
