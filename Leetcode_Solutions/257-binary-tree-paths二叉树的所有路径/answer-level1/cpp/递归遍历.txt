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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        string sr;
        func(root, res, sr);
        return res;
    }
    
    void func(TreeNode* root, vector<string>& res, string sr) {
        if (root == NULL) return;
        sr = sr.empty() ? sr + to_string(root->val) : sr + "->" + to_string(root->val);
        if (!root->left && !root->right) {
            res.push_back(sr);
            sr = "";
        }
        func(root->left, res, sr);
        func(root->right, res, sr);
    }
};
```
