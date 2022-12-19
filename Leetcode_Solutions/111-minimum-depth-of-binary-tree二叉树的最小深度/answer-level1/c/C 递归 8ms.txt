```
int minDepth(struct TreeNode* root){
    //return root ? 1 + (root->left && root->right ? fmin(minDepth(root->left), minDepth(root->right)) : minDepth(root->left ? root->left : root->right)) : 0;
    if (!root)
        return 0;
    else
    {
        if ((!root->left) && (!root->right))
            return 1;
        else if (root->left && root->right)
            return 1 + fmin(minDepth(root->left), minDepth(root->right));
        else if (root->left)
            return 1 + minDepth(root->left);
        else
            return 1 + minDepth(root->right);
    }
}
```
