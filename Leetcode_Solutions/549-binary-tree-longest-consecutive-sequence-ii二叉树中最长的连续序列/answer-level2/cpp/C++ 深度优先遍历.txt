# 思路：
考虑子节点逆序最大长度与顺序最大长度，然后综合得出结果
```C++ []
class Solution {
public:
    pair<int, int> dfs(TreeNode* root, int& res) {
        if (root == NULL) return {0, 0};
        auto l = dfs(root->left, res);
        auto r = dfs(root->right, res);
        int l1 = 0;
        int l2 = 0;
        int r1 = 0;
        int r2 = 0;
        if (root->right && root->right->val + 1 == root->val) {
            r1 = r.first;
        } else if (root->right && root->right->val - 1 == root->val) {
            r2 = r.second;
        }
        if (root->left && root->left->val + 1 == root->val) {
            l1 = l.first;
        } else if (root->left && root->left->val - 1 == root->val) {
            l2 = l.second;
        }
        int len = max(l1 + 1 + r2, l2 + 1 + r1);
        res = max(res, len);
        return {max(l1, r1) + 1, max(l2, r2) + 1};
    }
    int longestConsecutive(TreeNode* root) {
        int res = 0;
        dfs(root, res);
        return res;
    }
};
```

![image.png](https://pic.leetcode-cn.com/88cb8d87173841e47d993d9f37dd5633251980ad3b7ef0dffcc85bc6f7910052-image.png)
