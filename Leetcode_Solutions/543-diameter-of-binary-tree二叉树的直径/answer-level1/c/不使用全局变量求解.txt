速度巨慢。
```
int findLength(struct TreeNode *root){
    if(root == NULL){
        return 0;
    }
    int left = findLength(root->left);
    int right = findLength(root->right);
    return left > right ? left + 1 : right + 1;
}

int diameterOfBinaryTree(struct TreeNode* root){
    if(root == NULL){
        return 0;
    }
    int left = findLength(root->left);
    int right = findLength(root->right);
    int l_r = diameterOfBinaryTree(root->left);
    int r_r = diameterOfBinaryTree(root->right);
    return left + right > l_r ? left + right > r_r?  left + right : r_r > l_r ? r_r : l_r :l_r > r_r ?l_r : r_r;
}
```