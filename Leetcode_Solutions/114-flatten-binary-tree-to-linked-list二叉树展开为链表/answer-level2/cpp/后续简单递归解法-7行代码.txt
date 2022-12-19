
    void flatten(TreeNode* root) {
        TreeNode* pre=NULL;
        if(root==NULL) return;
        flatten(root->right);
        flatten(root->left);
        root->right=pre;
        root->left=NULL;
        pre=root;
    }