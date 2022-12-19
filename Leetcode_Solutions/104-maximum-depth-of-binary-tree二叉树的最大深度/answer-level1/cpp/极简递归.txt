执行用时 :4 ms, 在所有 cpp 提交中击败了99.42%的用户
内存消耗 :19.3 MB, 在所有 cpp 提交中击败了54.52%的用户

    int maxDepth(TreeNode* root) {
        if(root==nullptr){
            return 0;
        }
        return 1+max(maxDepth(root->left),maxDepth(root->right));
    }