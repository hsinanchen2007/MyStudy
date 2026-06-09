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
private:
    bool helper(TreeNode* node, int sum) {
        if (sum == node->val && !node->left && !node->right) return true;
        if (!node->left && !node->right) return false;
        sum -= node->val;
        bool left = false, right = false;
        if (node->left) left = helper(node->left, sum);
        if (node->right) right = helper(node->right, sum);
        return left || right;
    }

public:
    bool hasPathSum(TreeNode* root, int sum) {
        if (!root) return false;
        return helper(root, sum);
    }
};
```