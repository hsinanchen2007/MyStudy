class Solution {
public:
    vector<vector<int>> res;
    void dfs(TreeNode* root, int level) {
        if (root == NULL)
            return;
        if (level == 0 || res.size() < (level+1)){
            res.push_back(vector<int>({root->val}));
        } else {
            res[level].push_back(root->val);
        }
        dfs(root->left, level+1);
        dfs(root->right, level+1);
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        int level = 0;
        dfs(root, level);
        return res;
    }
};