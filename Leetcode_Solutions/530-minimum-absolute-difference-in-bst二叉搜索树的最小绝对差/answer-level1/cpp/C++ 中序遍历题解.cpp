### 解题思路
prev存储前继数
然后与当前数做差

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
    void dfs(TreeNode* root, int& prev, int& res) {
        if (root == NULL) return;
        dfs(root->left, prev, res);
        if (prev >= 0) res = min(res, root->val - prev);
        prev = root->val;
        dfs(root->right, prev, res);
    }
    int getMinimumDifference(TreeNode* root) {
        int prev = -1;
        int res = INT_MAX;
        dfs(root, prev, res);
        return res;
    }
};
```

![image.png](https://pic.leetcode-cn.com/1d78f36e0eb704c2d32efbed956507ba0c4d9c9cd31b35795d2c7800cf1c46f3-image.png)
