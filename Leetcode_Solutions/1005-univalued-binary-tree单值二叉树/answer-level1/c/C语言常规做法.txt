利用递归即可解决。这也是人生第一次用goto。
```c
bool isUnivalTree(struct TreeNode* root){
    if(root->left){
        if(root->left->val!=root->val) return 0;
        if(isUnivalTree(root->left))
            goto pos;
        else return 0;
    }
    pos:
    if(root->right){
        if(root->right->val!=root->val) return 0;
        return isUnivalTree(root->right);
    }
    return 1;
}
```