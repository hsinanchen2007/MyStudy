### 解题思路
此处撰写解题思路

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
    bool isSymmetric(TreeNode* root) {
        if (root == NULL) {
            return true;
        }
        if ((root->left && !root->right) || (!root->left && root->right)) {
            return false;
        }
        if (root->left && root->right) {
            if (root->left->val != root->right->val) {
                return false;
            }
        }
        return IsSymmetricCore(root->left, root->right);
    }
    bool IsSymmetricCore(TreeNode* left, TreeNode* right) {
        if (left == NULL && right == NULL) {
            return true;
        }
        if (!left || !right || left->val != right->val) {
            return false;
        }
        return IsSymmetricCore(left->left, right->right) && IsSymmetricCore(left->right, right->left);
    }
};
```