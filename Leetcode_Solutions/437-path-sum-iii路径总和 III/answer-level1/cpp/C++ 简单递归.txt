```
// Solution 1
class Solution {
public:
    vector<int> dfs(TreeNode* root, int sum, int& count) {
        vector<int> res;
        if (root == NULL) return res;
        res.push_back({root->val});
        auto left = dfs(root->left, sum, count);
        auto right = dfs(root->right, sum, count);
        for (auto x : left) res.push_back(x + root->val);
        for (auto x : right) res.push_back(x + root->val);
        for (auto x : res) count += x == sum;
        return res;
    }
    int pathSum(TreeNode* root, int sum) {
        int res = 0;
        dfs(root, sum, res);
        return res;
    }
};

// Solution2
class Solution {
public:
    int path(TreeNode* root, int sum) {
        if (root == NULL) return 0;
        return (root->val == sum) + path(root->left, sum - root->val) + path(root->right, sum - root->val);
    }
    int pathSum(TreeNode* root, int sum) {
        if (root == NULL) return 0;
        return path(root, sum) + pathSum(root->left, sum) + pathSum(root->right, sum);
    }
};
```

![image.png](https://pic.leetcode-cn.com/615dc6ab117bbc46ae0f9b5697cd30d494586fa0a9574b0e39fc80724730d2ea-image.png)

