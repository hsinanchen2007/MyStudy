速度是真的慢。。。

    int depth(TreeNode* root){
        if(root==nullptr) return 0;
        return 1+max(depth(root->left),depth(root->right));
    }
    bool isBalanced(TreeNode* root) {
        if(root==nullptr) return true;
        return abs(depth(root->left)-depth(root->right))<2&&isBalanced(root->left)&&isBalanced(root->right);
    }