```
typedef struct TreeNode TreeNode;

int maxDepthOrder(TreeNode *root) {
    int leftDepth = 0;
    int rightDepth = 0;

    if (root == NULL) {
        return 0;
    } 
    leftDepth = maxDepthOrder(root->left);
    rightDepth = maxDepthOrder(root->right);
    return leftDepth > rightDepth ? leftDepth + 1 : rightDepth + 1;
}

int maxDepth(struct TreeNode* root){
    int returnValue;
    returnValue = maxDepthOrder(root);

    return returnValue;
}
```
