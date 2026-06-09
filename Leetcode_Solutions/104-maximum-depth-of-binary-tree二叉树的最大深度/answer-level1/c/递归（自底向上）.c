```
int maxDepth(struct TreeNode* root){
    if (root == NULL) {
        return 0;
    }
    int leftDepth = maxDepth(root->left);
    int rightDepth = maxDepth(root->right);
    return leftDepth < rightDepth ? rightDepth + 1 : leftDepth + 1;    
}

```
