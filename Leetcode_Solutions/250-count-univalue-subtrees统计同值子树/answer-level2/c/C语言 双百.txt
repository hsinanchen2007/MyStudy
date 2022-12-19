简单递归
```
int g_sum = 0;
int IsUnivaltree(struct TreeNode* root){
    if (root == NULL) {
        return 1;
    }
    int left = IsUnivaltree(root->left);
    int right = IsUnivaltree(root->right);

    if (root->left != NULL && (left == 0 || root->val != root->left->val)) {
        return 0;
    } 
    if (root->right != NULL && (right == 0 || root->val != root->right->val)) {
        return 0;
    }
    g_sum++;
    return 1;
}
int countUnivalSubtrees(struct TreeNode* root){
    if (root == NULL) {
        return 0;
    }
    g_sum = 0;
    IsUnivaltree(root);
    return g_sum;
}
```
