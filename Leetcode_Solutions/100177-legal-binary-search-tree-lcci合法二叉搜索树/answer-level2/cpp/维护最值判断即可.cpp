不说明数据范围出题人属实牛逼嗷，全家发财。
```c++
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(long long x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
  bool isValidBST(TreeNode* root) {
    if (root == NULL) return 1;
    function<int(TreeNode*, long long, long long)> dfs = [&](TreeNode* rt, long long lo, long long hi) {
      if (rt == NULL) return 1;
      if (!(rt->val > lo && rt->val < hi)) return 0;
      return dfs(rt->left, lo, rt->val) & dfs(rt->right, rt->val, hi);
    };
    return dfs(root, -1E18, 1E18);
  }
};
```