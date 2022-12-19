```
bool isUnivalTree(struct TreeNode* root){
    if (root == NULL) {
        return true;
    }

    if (root->left != NULL && root->right != NULL) {
        //判断中间和两侧
        if (root->val == root->left->val && root->left->val == root->right->val) {
            return isUnivalTree(root->left)&&isUnivalTree(root->right);
        } else {
            return false;
        }
    } else if (root->left !=NULL && root->right == NULL) {
        if (root->val == root->left->val) {
            return isUnivalTree(root->left);
        } else {
            return false;
        }
    } else if (root->right !=NULL && root ->left == NULL) {
        if (root->val == root -> right -> val) {
            return isUnivalTree(root->right);
        } else {
            return false;
        }
    } else {
        return true;
    }
}
```