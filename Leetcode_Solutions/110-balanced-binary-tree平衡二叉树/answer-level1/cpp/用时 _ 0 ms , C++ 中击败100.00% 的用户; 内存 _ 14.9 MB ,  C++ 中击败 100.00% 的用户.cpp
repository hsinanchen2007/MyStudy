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
    
    bool f = true;
    int maxDepth (TreeNode* root)
    {
        if (root == nullptr) return 0;
        int leftDepth = maxDepth(root->left);
        int rightDepth = maxDepth(root->right);
        if (abs(leftDepth - rightDepth)>1) f = false;
        return  max(leftDepth, rightDepth)+ 1;
    }
    bool isBalanced(TreeNode* root) {
        maxDepth(root);
        return f;      
    }
};
```