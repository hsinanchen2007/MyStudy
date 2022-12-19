```
class Solution {
public:
    int maxPathSum(TreeNode* root) {
        int res = INT_MIN;
        maxPathSum(root, res);
        return res;
    }
    int maxPathSum(TreeNode* root, int& res) {
        if (!root)
            return 0;
        int left = maxPathSum(root->left, res);
        int right = maxPathSum(root->right, res);
        int temp = root->val;
        if (left > 0)
            temp += left;
        if (right > 0)
            temp += right;
        res = max(res, temp);
        return max(0,max(left,right)) + root->val;
    }
};
```
