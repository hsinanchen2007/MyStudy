
递归一：超时
在想改进的方法！
```
int maxDepth(struct TreeNode* root){
        int maxdepth=0;
        if(root==NULL)
        {
            return 0;
        }
        else
        {
            maxdepth = maxDepth(root->left) < maxDepth(root->right) ? maxDepth(root->right) : maxDepth(root->left) ;
            return maxdepth+1;
        }

}

```
