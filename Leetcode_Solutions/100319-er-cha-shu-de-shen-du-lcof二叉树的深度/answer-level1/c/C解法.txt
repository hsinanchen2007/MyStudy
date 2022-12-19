
# 代码：
```
int maxDepth(struct TreeNode* root){
    if(root == 0) return 0;

    int leftmaxDepth = maxDepth(root->left),
        rightmaxDepth = maxDepth(root->right);

    return(leftmaxDepth < rightmaxDepth? rightmaxDepth + 1 : leftmaxDepth + 1);
}
}
```
