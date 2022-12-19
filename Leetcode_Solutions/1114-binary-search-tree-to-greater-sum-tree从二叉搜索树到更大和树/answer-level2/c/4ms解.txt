遍历累加，遍历顺序为右中左，自定义整型变量记录累加的数值。
```
int n;
void ss(struct TreeNode* root){
    int p;
    if(!root->right&&!root->left){
        p=n+root->val;
        root->val+=n;
        n=p;
        return ;
    }
    if(root->right)
        ss(root->right);
    p=n+root->val;
    root->val+=n;
    n=p;
    if(root->left)
        ss(root->left);
}
struct TreeNode* bstToGst(struct TreeNode* root){
    n=0;
    ss(root);
        return root;
}
```
