执行用时 :4 ms, 在所有 cpp 提交中击败了93.94%的用户
内存消耗 :14.5 MB, 在所有 cpp 提交中击败了98.67%的用户

    bool mirror(TreeNode* root1,TreeNode* root2){
        if(root1==nullptr&&root2==nullptr){
            return true;
        }
        if(root1==nullptr||root2==nullptr){
            return false;
        }
        return (root1->val==root2->val)&&mirror(root1->left,root2->right)&&mirror(root1->right,root2->left);
    }
    bool isSymmetric(TreeNode* root) {
        return mirror(root,root);
    }