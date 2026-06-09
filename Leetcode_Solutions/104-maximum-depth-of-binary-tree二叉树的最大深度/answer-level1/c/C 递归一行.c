```
int maxDepth(struct TreeNode* root){
    return !root? 0 : fmax(maxDepth(root->left), maxDepth(root->right)) + 1;
}
```
