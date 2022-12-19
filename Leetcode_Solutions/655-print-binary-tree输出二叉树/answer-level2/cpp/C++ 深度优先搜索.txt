### 解题思路
1，先求出树的最大深度，根据最大深度初始化结果矩阵
2，DFS填充矩阵值

### 代码

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
    int maxDepth(TreeNode* root) {
        if (root == NULL) return 0;
        return 1 + max(maxDepth(root->left), maxDepth(root->right));
    }
    void dfs(TreeNode* root, int k, int r, int c, vector<vector<string> >& res) {
        if (root == NULL) return;
        res[r][c] = to_string(root->val);
        k >>= 1;
        dfs(root->left, k, r + 1, c - k, res);
        dfs(root->right, k, r + 1, c + k, res);
    }
    vector<vector<string>> printTree(TreeNode* root) {
        int R = maxDepth(root);
        int C = (1 << R) - 1;
        vector<vector<string> > res(R, vector<string>(C, ""));
        int k = 1 << (R - 1);
        int r = 0;
        int c = C >> 1;
        dfs(root, k, r, c, res);
        return res;
    }
};
```

![image.png](https://pic.leetcode-cn.com/a1365e8e05b640377b8ae2793e9a2d8bb40e02d50405d7198708fff1f534bb29-image.png)
