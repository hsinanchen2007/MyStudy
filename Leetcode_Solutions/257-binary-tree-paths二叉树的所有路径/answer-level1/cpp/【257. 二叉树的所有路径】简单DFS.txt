### 思路


### 代码

```cpp
class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        if (root == nullptr) return res;
        string cur;
        dfs(root, res, cur);
        return res;
    }
    void dfs(TreeNode *root, vector<string> &res, string cur) {
        cur += to_string(root->val);
        if (root->left == nullptr && root->right == nullptr) {
            res.push_back(cur);
            return;
        }
        if (root->left) dfs(root->left, res, cur + "->");
        if (root->right) dfs(root->right, res, cur + "->");
    }
};
```