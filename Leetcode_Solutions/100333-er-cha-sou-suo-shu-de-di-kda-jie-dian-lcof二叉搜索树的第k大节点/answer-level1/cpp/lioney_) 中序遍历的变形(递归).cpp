```
class Solution {
public:
    int kthLargest(TreeNode* root, int k) {
        int res = 0, cur = 0;
        helper(root, k, cur, res);
        return res;
    }
    void helper(TreeNode* root, int k, int& cur, int& res) {
        if(!root) return;
        helper(root->right, k, cur, res);
        if(++cur == k) {
            res = root->val;
            return;
        }
        helper(root->left, k, cur, res);
    }
};
```
