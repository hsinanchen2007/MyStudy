暴力遍历所有的可能路径，然后看是否满足条件
```
class Solution {
public:
    vector<vector<int> > path(TreeNode* root) {
        vector<vector<int> > res;
        if (root == NULL) return res;
        if (root->left == NULL && root->right == NULL) return {{root->val}};
        res = path(root->left);
        auto right = path(root->right);
        res.insert(res.end(), right.begin(), right.end());
        for (auto& v : res) v.push_back(root->val);
        return res;
    }
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int> > res;
        auto all_paths = path(root);
        for (auto& v : all_paths) {
            if (accumulate(v.begin(), v.end(), 0) == sum) {
                reverse(v.begin(), v.end());
                res.push_back(v);
            }
        }
        return res;
    }
};
```
![image.png](https://pic.leetcode-cn.com/4bdc15062a56d56dac1ae2d7d6107b0822a86a2e027fdaf39fe631416020cf73-image.png)
