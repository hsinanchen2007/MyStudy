通过递归即可解决，思路较简单，不再赘述。
```c
int maxDepth(struct TreeNode* root){
    if(root==0) return 0;
    int heightLeft=1,heightRight=1;
    if(root->left)
        heightLeft+=maxDepth(root->left);
    if(root->right)
        heightRight+=maxDepth(root->right);
    return heightLeft>heightRight?heightLeft:heightRight;
}
```