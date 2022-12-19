int rangeSumBST(struct TreeNode* root, int L, int R){
    int res=0;
    if(root==NULL) return 0;
    else{
         int v=root->val;
        if(v>R||v<L)  v=0;
        return v+rangeSumBST(root->left,L,R)+rangeSumBST(root->right,L,R);
    }
}
