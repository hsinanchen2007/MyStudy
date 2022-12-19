```
class Solution {
public:
    int maxPathSum(TreeNode* root) {
        int res = INT_MIN;
        helper(root, res);
        return res;
    }

    int helper(TreeNode*root, int& res) {
        if(!root) return 0;
        int left = max(helper(root->left, res), 0);
        int right = max(helper(root->right, res), 0);
        res = max(res, left + right + root->val);
        return max(left, right) + root->val;
    }
};
```
