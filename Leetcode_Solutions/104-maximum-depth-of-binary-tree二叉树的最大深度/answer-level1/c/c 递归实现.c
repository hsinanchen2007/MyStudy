int maxDepth(struct TreeNode* root){
    int leftHight = 0;
    int rightHight = 0;
    if (root == NULL) {
        return 0;
    }
    leftHight = maxDepth(root->left) + 1;
    rightHight = maxDepth(root->right) + 1;
    return leftHight > rightHight ? leftHight : rightHight;
}