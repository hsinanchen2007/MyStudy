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
    TreeNode* mirrorTree(TreeNode* root) {
        if(root==NULL)
            return root;
        TreeNode* newRoot=new TreeNode(root->val);
        newRoot->left=mirrorTree(root->right);
        newRoot->right=mirrorTree(root->left);
        return newRoot;
    }
};
```
