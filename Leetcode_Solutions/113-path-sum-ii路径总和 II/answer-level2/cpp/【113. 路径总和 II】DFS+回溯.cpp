## 思路一：回溯

### 代码
```c++
class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> res;
        if (root) {
            vector<int> path;
            find(root, sum, res, path);
        }
        return res;
    }

    void find(TreeNode *root, int sum, vector<vector<int>> &res, vector<int> &path) {
        sum -= root->val;
        path.push_back(root->val);
        if (sum == 0 && !root->left && !root->right) {
            res.push_back(path);
            return;
        }
        if (root->left) {
            find(root->left, sum, res, path);
            path.pop_back(); //回溯
        }
        if (root->right) {
            find(root->right, sum, res, path);
            path.pop_back(); //回溯
        }
    }
};
```

### 另一种写法
```c++
class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> res;
        vector<int> path;
        if (!root) {
            return res;
        }
        find(root, sum, res, path);
        return res;
    }
    void find(TreeNode *root, int sum, vector<vector<int>> &res, vector<int> &path) {
        if (!root) {
            return;
        }
        path.push_back(root->val);
        if (!root->left && !root->right && sum == root->val) {
            res.push_back(path);
        }
        find(root->left, sum-root->val, res, path);
        find(root->right, sum-root->val, res, path);
        path.pop_back();
    }
};
```
