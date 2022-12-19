```C++ []
class Solution {
public:
    void dfs(TreeNode* root, int d, map<int, int>& m) {
        if (root == NULL) return;
        if (m.count(d) == 0) m[d] = root->val;
        else m[d] = max(m[d], root->val);
        dfs(root->left, d + 1, m);
        dfs(root->right, d + 1, m);
    }
    vector<int> largestValues(TreeNode* root) {
        map<int, int> m;
        dfs(root, 0, m);
        vector<int> res;
        for (auto& p : m) {
            res.push_back(p.second);
        }
        return res;
    }
};
```

![image.png](https://pic.leetcode-cn.com/9a8dc9a558e814ad79f9efd326ef2b59e6e129bb456f9ffa313a170b1c434bcf-image.png)
