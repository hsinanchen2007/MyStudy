### 解题思路
递归计算树的高度，如果左右子树高度相差超过1，可以返回-1作为标记。表示不是平衡二叉树。

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
    int do_isBalanced_findDepth(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        int leftDep = do_isBalanced_findDepth(root->left);
        if (leftDep == -1) {
            return -1;
        }
        int rightDep = do_isBalanced_findDepth(root->right);
        if (rightDep == -1) {
            return -1;
        }
        if (abs(rightDep - leftDep) > 1) {
            return -1;
        }
        return 1+ max(rightDep, leftDep);
    }

    bool isBalanced(TreeNode* root) {
        return do_isBalanced_findDepth(root) != -1;
    }
};
```