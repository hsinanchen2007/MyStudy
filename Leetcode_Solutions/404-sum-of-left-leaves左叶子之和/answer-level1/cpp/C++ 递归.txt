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
    int sumOfLeftLeaves(TreeNode* root) {
        int res = 0;
        if(!root)
            return 0;
        if(root->left && !root->left->left && !root->left->right)
             res += root->left->val;
        res += sumOfLeftLeaves(root->left) + sumOfLeftLeaves(root->right);
        return res;
    }
};
```