思路：运用递归，左右子树符合平衡二叉树同时左右子树高度差不大于1。

```
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
    bool isBalanced(TreeNode* root) {
        if (!root) return true;
        return abs(getHight(root->left) - getHight(root->right)) <= 1 && isBalanced(root->left) && isBalanced(root->right);
    }

    int getHight(TreeNode* node)
    {
        if (!node) return 0;
        return  max(getHight(node->left), getHight(node->right)) + 1;
    }
};
```
