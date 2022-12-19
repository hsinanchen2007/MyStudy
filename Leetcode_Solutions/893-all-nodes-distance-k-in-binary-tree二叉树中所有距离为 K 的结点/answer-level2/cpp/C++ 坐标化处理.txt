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
public:
    using DT = long long;
    map<TreeNode*, DT> memo;
    void dfs(TreeNode* root, DT n) {
        if (root == NULL) return;
        memo[root] = n;
        dfs(root->left, 2 * n + 1);
        dfs(root->right, 2 * n + 2);
    }
    int dist(DT n1, DT n2) {
        int res = 0;
        while (n1 != n2) {
            if (n1 > n2) {
                n1 = (n1 - 1) / 2;
            } else {
                n2 = (n2 - 1) / 2;
            }
            ++res;
        }
        return res;
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
        dfs(root, 0);
        vector<int> res;
        DT t = memo[target];
        for (auto& p : memo) {
            if (dist(p.second, t) == K) {
                res.push_back(p.first->val);
            }
        }
        return res;
    }
};
```

![image.png](https://pic.leetcode-cn.com/df2d8dba8e9d5d55c9c8fd6894dae301d0fda8df3e4d89dc431e38ed07dfecfb-image.png)

