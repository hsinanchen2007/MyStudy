用递归即可解决。迭代法待更。
```c
int sumOfLeftLeaves(struct TreeNode* root){
    int sum=0;
    if(root==0) return 0;
    if(root->left){
        if(root->left->left==0&&root->left->right==0)
            sum=root->left->val;
        else sum=sumOfLeftLeaves(root->left);
    }
    sum=sum+sumOfLeftLeaves(root->right);
    return sum;
}
```