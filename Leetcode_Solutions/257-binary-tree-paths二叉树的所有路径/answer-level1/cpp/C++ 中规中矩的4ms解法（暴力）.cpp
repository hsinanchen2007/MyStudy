```
class Solution {
public:
    vector<string> ans;
    vector<string> binaryTreePaths(TreeNode* root) {
        help(root, "");
        return ans;
    }

    void help(TreeNode* root, string path) {
        if (!root) return;

        path += to_string(root->val);
        if (!root->left && !root->right) ans.push_back(path);
        else {
            path += "->";
            help(root->left, path);
            help(root->right, path);
        }
    }
};
```