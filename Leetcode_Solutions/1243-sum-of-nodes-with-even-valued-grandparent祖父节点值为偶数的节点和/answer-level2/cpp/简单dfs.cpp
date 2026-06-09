

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
    int res;
    int sumEvenGrandparent(TreeNode* root) {
        dfs(root);
        return res;
    }
    void dfs(TreeNode* root){
        if(!root || (!root->left && !root->right))return ;
        if(!(root->val & 1)){
            if(root->left && root->left->left)res += root->left->left->val;
            if(root->left && root->left->right)res += root->left->right->val;
            if(root->right && root->right->left)res += root->right->left->val;
            if(root->right && root->right->right)res += root->right->right->val;
        }
        if(root->left)dfs(root->left);
        if(root->right)dfs(root->right);
    }
};
```