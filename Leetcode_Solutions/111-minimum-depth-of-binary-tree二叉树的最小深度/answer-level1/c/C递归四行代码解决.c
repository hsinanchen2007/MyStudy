

```
int minDepth(struct TreeNode* root){
    if (!root) return 0;
    // 单节点计算左右子树最大深度
    if (!root->left && root->right || !root->right && root->left) 
        return fmax(minDepth(root->left), minDepth(root->right)) + 1;;
    // 双节点计算左右子树最小深度
    return fmin(minDepth(root->left), minDepth(root->right)) + 1;
}

```

