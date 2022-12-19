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
    bool isMirror(TreeNode *left, TreeNode *right) {
        if (!left && !right) {
            return true;
        } else if (!(left && right)) {
            return false;
        } else if (left->val != right->val) {
            return false;
        } else {
            return isMirror(left->left, right->right) &&
                    isMirror(left->right, right->left);
        }
    }

    bool isSymmetric(TreeNode* root) {
        if (!root) {
            return true;
        }
        return isMirror(root->left, root->right);
    }
};
```