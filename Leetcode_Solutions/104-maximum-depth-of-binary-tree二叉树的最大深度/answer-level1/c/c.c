递归
```
int maxDepth(struct TreeNode* root){
    int leftMax=0,rightMax=0;
    if(root==NULL) return 0;
    else{
        leftMax=maxDepth(root->left);
        rightMax=maxDepth(root->right);
        return (leftMax>rightMax?leftMax:rightMax)+1;
    }
}
```
