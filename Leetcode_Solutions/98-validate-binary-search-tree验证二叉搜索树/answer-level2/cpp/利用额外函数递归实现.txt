本题关键是给出左右边界，并不断刷新，因为是线索二叉树，所以左子树均小于根节点，右子树均大于根节点。其中边界值应设置为LONG_MAX和LONG_MIN.
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        if(root==NULL)return true;
        long V=root->val;
        bool A=iscorrect(root->left,LONG_MIN,V);
        bool B=iscorrect(root->right,V,LONG_MAX);
        return A&B;
    }
    bool iscorrect(TreeNode* root,long L,long R){
        if(root==NULL)return true;
        if(root->val>=R||root->val<=L)return false;
        else{
            long V=root->val;
            bool A=iscorrect(root->left,L,V);
            bool B=iscorrect(root->right,V,R);
            return A&B;
        } 
    }
};