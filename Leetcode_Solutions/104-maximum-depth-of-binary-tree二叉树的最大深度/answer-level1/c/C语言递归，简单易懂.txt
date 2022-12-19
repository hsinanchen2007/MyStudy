```
int maxDepth(struct TreeNode* root){
    int lhigh,rhigh;
    if(root==NULL)
    {
        return 0;
    }
    lhigh=maxDepth(root->left);//遍历左子树
    rhigh=maxDepth(root->right);//遍历右子树
    return lhigh>rhigh?(lhigh+1):(rhigh+1);//判断大小
}
```
