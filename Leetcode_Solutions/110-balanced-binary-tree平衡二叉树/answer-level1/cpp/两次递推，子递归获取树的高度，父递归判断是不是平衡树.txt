### 解题思路
关键概念，平衡二叉树满足3个条件
1. 自身的左子树和右子树的高度差小于2
2. 左子树也是平衡二叉树
3. 右子树也是平衡二叉树

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
    int getHight(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        return max(getHight(root->left), getHight(root->right)) + 1;
    }
    bool isBalanced(TreeNode* root) {
        if (root == nullptr) {
            return true;
        }
        int leftHight = getHight(root->left);
        int rightHight = getHight(root->right);
        if (abs(leftHight - rightHight) < 2 && isBalanced(root->left) && isBalanced(root->right)) {
            return true;
        }
        return false;   
    }
};
```