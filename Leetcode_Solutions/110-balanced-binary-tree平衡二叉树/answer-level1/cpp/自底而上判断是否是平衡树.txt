### 解题思路
自底而上，将树的高度作为一个参数传进函数；先判断左右子树是否满足平衡树，再判断根节点是否满足平衡树。

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
    bool isBalanced(TreeNode* root) {
        int height;
        return isBalancedHelp(root, height);
    }

    bool isBalancedHelp(TreeNode* root, int& height)
    {
        if(!root)
        {
            height = 0;
            return true;
        }

        int left, right;
        int lebool = isBalancedHelp(root->left, left);
        int ribool = isBalancedHelp(root->right, right);
        height = max(left, right) +1;
        return lebool && ribool && abs(left-right) < 2;
    }
};
```