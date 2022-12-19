### 解题思路
    使用递归遍历二叉树，遇到与根节点值不相等就返回false,遇到一个false就判定不为单值二叉树.

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
    bool isUnivalTree(TreeNode* root) {
        return isVaild(root, root->val);
    }


    bool isVaild(TreeNode* root, int n)
    {
        if (!root)
            return true;
        if (root->val != n) 
            return false;
        return isVaild(root->left, n) && isVaild(root->right, n);
    }
};
```