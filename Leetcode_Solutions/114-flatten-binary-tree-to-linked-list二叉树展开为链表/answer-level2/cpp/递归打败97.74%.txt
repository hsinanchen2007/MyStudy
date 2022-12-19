```
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
    void flatten(TreeNode* root) {
        if(!root) return;
        if(!root->left&&!root->right) return;
        flatten(root->left);
        flatten(root->right);
        TreeNode* leftnode=root->left;
        TreeNode* rightnode=root->right;
        root->left=NULL;
        if(leftnode)
        {
            root->right=leftnode;
            while(leftnode->right)
            {
                leftnode=leftnode->right;
            }
            leftnode->right=rightnode;
        }
    }
};
```
