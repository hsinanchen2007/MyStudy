### 解题思路
利用递归法, 镜像对称 = 左孩子值 == 右孩子值,并且左孩子的左子树和右孩子的右子树相同,左孩子的右子树和右孩子的左子树相同

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
        if (!root) return true;
        if (!root->left && !root->right) return true;
        if (!root->left || !root->right) return false;
        return isSymmetric_helper(root->left, root->right);
    }

    bool isSymmetric_helper(TreeNode *left, TreeNode *right) {
        if (!left && !right) {
            return true;
        } else if (!left) {
            return false;
        } else if (!right) {
            return false;
        } else {
            return left->val == right->val && isSymmetric_helper(left->left, right->right) && isSymmetric_helper(right->left, left->right);
        }
    }
};
```