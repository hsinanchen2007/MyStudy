```cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
    bool dfs(TreeNode* root, int cur, int sum) {
        if (!root) return false;
        if (!root->left && !root->right && cur + root->val == sum) return true;
        return dfs(root->left, cur + root->val, sum) || dfs(root->right, cur + root->val, sum);
    }
public:
    bool hasPathSum(TreeNode* root, int sum) {
        if (root == nullptr) return false;
        return dfs(root, 0, sum);
    }
};
```