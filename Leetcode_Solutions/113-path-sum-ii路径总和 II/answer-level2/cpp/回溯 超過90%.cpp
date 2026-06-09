```
void helper(TreeNode* root, vector<vector<int>>& ans, vector<int>& res, int curDel) {
        if (root == nullptr) {
            return;
        }
        res.push_back(root->val);
        curDel -= root->val;
        if (root->left == nullptr && root->right == nullptr) {
            if (curDel == 0) ans.push_back(res);
        }
        if (root->left != nullptr)
            helper(root->left, ans, res, curDel);
        if (root->right != nullptr)
            helper(root->right, ans, res, curDel);
        res.pop_back();
        return;
    }
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<int> res;
        vector<vector<int>> ans;
        helper(root, ans, res, sum);
        return ans;
    }
```
