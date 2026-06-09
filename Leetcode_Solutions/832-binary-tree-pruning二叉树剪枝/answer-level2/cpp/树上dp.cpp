


```c++ []
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
    map<TreeNode*,int> Hash;
    void dfs(TreeNode* root){
        if(root -> left == NULL && root -> right == NULL){
            if(root->val == 1) Hash[root] = 1;
            else Hash[root] = 0;
            return;
        }
        if(root -> left != NULL){
            dfs(root -> left);
            if(Hash[root -> left] == 1) Hash[root] = 1;
        }
        if(root -> right != NULL){
            dfs(root -> right);
            if(Hash[root -> right] == 1) Hash[root] = 1;
        }
        if(root -> val == 1) Hash[root] = 1;
    }
    void cut(TreeNode* & root){
        if(root == NULL) return;
        if(root -> left == NULL && root -> right == NULL) return ;
        if(root -> left != NULL && Hash[root->left] == 0) root -> left = NULL;
        if(root -> right != NULL && Hash[root->right] == 0) root -> right = NULL;
        if(root -> left != NULL) cut(root -> left);
        if(root -> right != NULL) cut(root -> right);
    }
    TreeNode* pruneTree(TreeNode* root) {
        dfs(root);
        if(Hash[root] == 0) return NULL;
        cut(root);
        return root;
    }
};
```
