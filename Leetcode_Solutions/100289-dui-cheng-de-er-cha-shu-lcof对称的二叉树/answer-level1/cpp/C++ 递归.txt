### 解题思路
使用递归，需要找到规律，每次其实对比了两根树的根节点之后，然后再将左树的右子树和右树的左子树进行递归对比，并且右树的右子树和左树的左子树进行递归对比。

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
        return do_isSymmetric(root, root);
    }

    bool do_isSymmetric(TreeNode* leftRoot, TreeNode* rightRoot) {
        if(leftRoot == NULL && rightRoot == NULL) return true;
        if (leftRoot == NULL) return false;
        if (rightRoot == NULL) return false;
        if(leftRoot->val != rightRoot->val) return false;
        return do_isSymmetric(leftRoot->left, rightRoot->right) && do_isSymmetric(rightRoot->left, leftRoot->right);
    }
};
```