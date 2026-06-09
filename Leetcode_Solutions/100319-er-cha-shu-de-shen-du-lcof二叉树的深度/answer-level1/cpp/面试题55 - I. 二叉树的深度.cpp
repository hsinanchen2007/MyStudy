Dfs暴力搜索
```
class Solution {
private:
    void Dfs(TreeNode* root, int& ans, int depth)
    {
        if (root == nullptr) {
            ans = max(ans, depth);
            return;
        }
        Dfs(root->left, ans, depth + 1);
        Dfs(root->right, ans, depth + 1);
    }
public:
    int maxDepth(TreeNode* root) {
        int ans = 0;
        Dfs(root, ans, 0);
        return ans;
    }
};
```
