```
class Solution {
public:
    int minDiffInBST(TreeNode* root) {
        dfs(root);
        return res;
    }
    int prev = INT_MAX;
    int res = INT_MAX;
    void dfs(TreeNode* root){
        if (!root)
            return;
        dfs(root->left);
        res = min(abs(root->val - prev), res);
        prev = root->val;
        dfs(root->right);
    }
};
```
