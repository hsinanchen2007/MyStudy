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
    int helper(TreeNode* node, int &res) {
        if (!node) return 0;
        int left = 0, right = 0;
        left = helper(node->left, res);
        right = helper(node->right, res);
        int now = left + right + 1;
        res = max(res, now);
        return 1 + max(left, right);
    }

public:
    int diameterOfBinaryTree(TreeNode* root) {
        int res = 0;
        int pass = helper(root, res);
        return res > 0 ? res - 1 : res;
    }
};
```