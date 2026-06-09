```C++ []
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
    pair<int, int> helper(TreeNode* root, double& res) {
        if (root == NULL) return {0, 0};
        auto pl = helper(root->left, res);
        auto pr = helper(root->right, res);
        int count = pl.first + pr.first + 1;
        int sum = pl.second + pr.second + root->val;
        res = max(res, 1.0 * sum / count);
        return {count, sum};
    }
    double maximumAverageSubtree(TreeNode* root) {
        double res = 0;
        helper(root, res);
        return res;
    }
};
```

![image.png](https://pic.leetcode-cn.com/92c6fdd87dbd24fd856ad935e2b812a86637f4e94e25bc3041b0014eefb7fd10-image.png)
