    
    void mirror(TreeNode* root){
        if(root==nullptr) return;
        TreeNode* temp=root->left;
        root->left=root->right;
        root->right=temp;
        mirror(root->left);
        mirror(root->right);
    }
    TreeNode* invertTree(TreeNode* root) {
        mirror(root);
        return root;
    }