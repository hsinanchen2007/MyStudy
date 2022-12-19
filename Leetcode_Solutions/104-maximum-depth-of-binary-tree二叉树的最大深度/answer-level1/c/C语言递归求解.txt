递归终止条件：root=NULL——即叶子结点，返回0

递归体：左子树深度>右子树深度，则根深度为左子树+1；反之亦然。


```
int maxDepth(struct TreeNode* root){
    #终止条件
  if(!root) return 0;
    #递归体
  int left=maxDepth(root->left);
  int right=maxDepth(root->right);
  return  right>left?right+1:left+1;
}
```
