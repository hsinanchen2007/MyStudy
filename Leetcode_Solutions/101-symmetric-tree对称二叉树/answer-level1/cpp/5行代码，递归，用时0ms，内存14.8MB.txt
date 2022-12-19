class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        return isSymmetric(root,root);
    }
    bool isSymmetric(TreeNode *p,TreeNode *q) {
        if(p==NULL||q==NULL) return q==p;
        else return q->val==p->val &&isSymmetric(q->left,p->right) &&isSymmetric(q->right,p->left);        
    }        
};