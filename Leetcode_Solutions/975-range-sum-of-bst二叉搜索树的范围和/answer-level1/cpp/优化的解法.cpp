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
    int rangeSumBST(TreeNode* root, int L, int R) {
        if(!root)
            return 0;
      int left=rangeSumBST(root->left,L,R);
      int right=rangeSumBST(root->right,L,R);
      return (root->val<=R&&root->val>=L)?(left+right+root->val):(left+right);
        
    }
};