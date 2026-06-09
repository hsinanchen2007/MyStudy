# 思路：
深度优先遍历时记录所有出现过的值的频次信息即可

```C++ []
class Solution {
public:
    int dfs(TreeNode* root, unordered_map<int, int>& m, int& max_count) {
        if (root == NULL) return 0;
        int l = dfs(root->left, m, max_count);
        int r = dfs(root->right, m, max_count);
        int s = l + r + root->val;
        max_count = max(max_count, ++m[s]);
        return s;
    }
    vector<int> findFrequentTreeSum(TreeNode* root) {
        int max_count = 0;
        unordered_map<int, int> m;
        dfs(root, m, max_count);
        vector<int> res;
        for (auto& p : m) {
            if (p.second == max_count) {
                res.push_back(p.first);
            }
        }
        return res;
    }
};
```

![image.png](https://pic.leetcode-cn.com/cf1247017223d1c5816bc190aeb416fe1df5d249548ae17549daca98a38cf338-image.png)
