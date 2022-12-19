### 解题思路
我是完全按照平衡二叉树的概念来的。
首先计算任何一个二叉的高度，即getheight(TreeNode* root)函数，之后使用isBalanced函数，根据定义写下来这个函数的内容。

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
        if (root==nullptr) return true;
        if(fabs(getheight(root->left)-getheight(root->right))>1)
            return false;
        if(!isBalanced(root->left) || !isBalanced(root->right))
            return false;
        return true;
    }

    int getheight(TreeNode* root)
    {
        if(root==nullptr)
            return 0;
        return max(getheight(root->left) , getheight(root->right))+1;
    }
};
```