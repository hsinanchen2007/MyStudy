```
class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<int> tmp;
        helper(root, sum, tmp);
        return res;
    }
    void helper(TreeNode* root, int sum, vector<int>& tmp) {
        if(!root) return;
        tmp.push_back(root->val);
        if(sum == root->val && !root->left && !root->right) {
            res.push_back(tmp);
        }
        helper(root->left, sum-root->val, tmp);
        helper(root->right, sum-root->val, tmp);
        tmp.pop_back();
    }
private:
    vector<vector<int>> res;
};
```
