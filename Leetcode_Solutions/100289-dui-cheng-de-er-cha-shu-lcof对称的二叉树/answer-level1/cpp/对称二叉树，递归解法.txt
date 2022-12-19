子树A和子树B对称的条件是
A->val==B-> && A->left==B->right &&A->right==B->left
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
    bool isSymmetric(TreeNode* root) {
        if(root==nullptr)
        return true;
        
        return judge(root->left,root->right);

    }
    bool judge(TreeNode* A,TreeNode* B)
    {
        if(A==nullptr&&B==nullptr)
         return true;
        if(A==nullptr||B==nullptr||A->val!=B->val)
        return false;

        return judge(A->left,B->right)&&judge(A->right,B->left);
         
    }
};
```
