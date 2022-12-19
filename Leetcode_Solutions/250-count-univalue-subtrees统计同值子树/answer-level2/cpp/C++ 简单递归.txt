```
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
public:
    // p is the parent value of root
    pair<bool, int> dfs(TreeNode* root, int p, int& res) {
        if (root == NULL) return {true, p};
        auto l = dfs(root->left, root->val, res);
        auto r = dfs(root->right, root->val, res);
        if (l.first && r.first && l.second == root->val && r.second == root->val) {
            ++res;
            return {true, root->val};
        }
        return {false, root->val};
    }
    int countUnivalSubtrees(TreeNode* root) {
        if (root == NULL) return 0;
        int res = 0;
        dfs(root, 0, res);
        return res;
    }
};
```

![image.png](https://pic.leetcode-cn.com/6f66b248f24e716513c03f2a19f9cb20b46228f96f4373ca46437d8d77101e1d-image.png)
