# 思路
dfs的时候传入父节点的值以及截止到父节点的有效序列长度

```C++ []
class Solution {
public:
    void dfs(TreeNode* root, int p, int k, int& res) {
        res = max(res, k);
        if (root == NULL) return;
        if (root->val == p + 1) {
            dfs(root->left, root->val, k + 1, res);
            dfs(root->right, root->val, k + 1, res);
        } else {
            dfs(root->left, root->val, 1, res);
            dfs(root->right, root->val, 1, res);
        }
    }
    int longestConsecutive(TreeNode* root) {
        if (root == NULL) return 0;
        int res = 0;
        dfs(root->left, root->val, 1, res);
        dfs(root->right, root->val, 1, res);
        return res;
    }
};
```

![image.png](https://pic.leetcode-cn.com/55d8c32f527b4ea9916a06497ad7c040c351ed78e67ca2e272916ac46537167b-image.png)
