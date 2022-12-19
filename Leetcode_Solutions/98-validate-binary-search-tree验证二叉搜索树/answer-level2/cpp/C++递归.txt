class Solution {
public:
    bool isValidBST(TreeNode* root) {
        if(root==NULL) return true;
        long max=LONG_MAX,min=LONG_MIN;
        return check(root,max,min);
    }
private:
    bool check(TreeNode* root, long& max,long& min){
        //max, min ->the maximum and minimum values of subtree.
        if(!root) return true;
        long max_r,min_r,max_l,min_l;
        bool flag_l,flag_r;
        if(root->left==NULL){
            min=root->val;
            flag_l=true;
        }
        else{
            flag_l=check(root->left,max_l,min_l);
            min=min_l;
            if(root->val<=max_l) return false;
        }
        if(root->right==NULL){
            flag_r=true;
            max=root->val;
        } 
        else{
            flag_r=check(root->right,max_r,min_r);
            max=max_r;
            if(root->val>=min_r) return false;
        }
        return flag_l&flag_r;
    }
};