C语言实现
```C []
int calMaxRoot(struct TreeNode* root, int *maxRoot){
    if (NULL == root) return 0;
    int lLen = calMaxRoot(root->left, maxRoot);
    int rLen = calMaxRoot(root->right, maxRoot);
    if (lLen + rLen > *maxRoot) *maxRoot = lLen + rLen;
    return (lLen > rLen ? lLen : rLen) + 1;
}

int diameterOfBinaryTree(struct TreeNode* root){
    int maxRoot = 0;
    calMaxRoot(root, &maxRoot);
    return maxRoot;
}

```
