### 解题思路

![image.png](https://pic.leetcode-cn.com/edc58ec74e950e7e5756db3d08280e8510e77b8d7cb39d6eade2f80e42cab0fa-image.png)

递归思路：
L(root) = max(L(root->left), L(root->right), L(过root的最大路径))
L(过root的最大路径) = root->val + max(L(root->left单边), L(root->right单边), L(root->left单边) + L(root->right单边));
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
    int maxSinglePath(TreeNode* root) {
        if (!root) return 0;
        int res = max(maxSinglePath(root->left), maxSinglePath(root->right));  
        return max(root->val, root->val + res);
    }
    int maxPathSum(TreeNode* root) {
        if (!root) return 0;
        int l = maxSinglePath(root->left);
        int r = maxSinglePath(root->right);
        int res = root->val;
        if (l > 0) res += l;
        if (r > 0) res += r;
        if (root->left) res = max(res, maxPathSum(root->left));
        if (root->right) res = max(res, maxPathSum(root->right));
        return res;
    }
};
```