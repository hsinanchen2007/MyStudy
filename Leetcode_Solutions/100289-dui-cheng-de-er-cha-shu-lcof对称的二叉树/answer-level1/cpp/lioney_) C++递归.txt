```
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if(!root) return true;
        return helper(root->left, root->right);
    }
    bool helper(TreeNode* A, TreeNode* B) {
        if(!A && !B) return true;
        else if(A && !B || !A && B || A->val != B->val) return false;
        return helper(A->left, B->right) && helper(A->right, B->left);   
    }
};
```
