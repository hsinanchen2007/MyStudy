```c++
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
    bool isUnivalTree(TreeNode* root) {
        if (!root) return true;
        if (root->left && root->right) {
            return root->val == root->left->val 
                    && root->val == root->right->val
                    && isUnivalTree(root->left)
                    && isUnivalTree(root->right);
        } else if (root->left) {
            return root->val == root->left->val && isUnivalTree(root->left);
        } else if (root->right) {
            return root->val == root->right->val && isUnivalTree(root->right);
        } else {
            return true;
        }
    }
};
```