### 解题思路
学习官方的递归解法

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
        if(root == NULL)
            return true;
        return (root->left == NULL || (root->val == root->left->val) && isUnivalTree(root->left)) 
        && (root->right == NULL || (root->val == root->right->val) && isUnivalTree(root->right));
    }
};
```