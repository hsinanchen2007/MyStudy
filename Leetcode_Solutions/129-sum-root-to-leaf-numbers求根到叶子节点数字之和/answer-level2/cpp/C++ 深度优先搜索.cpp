```C++ []
class Solution {
public:
    void dfs(TreeNode* root, int p, int& res) {
        if (root == NULL) return;
        p = 10 * p + root->val;
        if (root->left == NULL && root->right == NULL) {
            res += p;
            return;
        }
        dfs(root->left, p, res);
        dfs(root->right, p, res);
    }
    int sumNumbers(TreeNode* root) {
        int res = 0;
        dfs(root, 0, res);
        return res;
    }
};
```

![image.png](https://pic.leetcode-cn.com/c8bf988ed75cda85a6594c3a28c833a01a9f7eed10fedc5b2d18cb37168dbc3b-image.png)
