class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
       if(!root)
            return false;
       return !root->left && !root->right ? root->val==sum ? true : false : 
               hasPathSum(root->left,sum-root->val) ||
                   hasPathSum(root->right,sum-root->val);
    }
};