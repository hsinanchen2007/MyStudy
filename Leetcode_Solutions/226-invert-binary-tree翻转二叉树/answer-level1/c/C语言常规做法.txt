通过递归即可解决，以下为第二次提交的版本。
```c
struct TreeNode* invertTree(struct TreeNode* root){
    if(root==0) return 0;
    struct TreeNode* tmp=root->left;
    root->left=invertTree(root->right);
    root->right=invertTree(tmp);
    return root;
}
```
以下为第一次提交的版本。
```c
void invert(struct TreeNode* root){
    struct TreeNode* tmpP=root->left;
    root->left=root->right;
    root->right=tmpP;
    if(root->left) invert(root->left);
    if(root->right) invert(root->right);
}

struct TreeNode* invertTree(struct TreeNode* root){
    if(root==0) return 0;
    invert(root);
    return root;
}
```