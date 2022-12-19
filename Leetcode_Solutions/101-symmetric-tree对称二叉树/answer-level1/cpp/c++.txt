### 解题思路

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
        if(!root)return true;    
        return dfs(root->left,root->right);
    }
    bool dfs(TreeNode* left,TreeNode* right){
        if(!left || !right)return !left && !right;
        return left->val == right->val && dfs(left->right,right->left) && dfs(left->left,right->right);
    }
};
```