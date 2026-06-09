我的遍历顺序是先右后左，先遍历再检查，检查下一个节点的值是否为0，下一个节点是否为叶子节点，若都满足，令下一个节点为NULL。
```
void ss(struct TreeNode* root){
    if(!root)
        return ;
    
    ss(root->right);
    if(root->right&&root->right->val==0&&!root->right->left&&!root->right->right)
        root->right=NULL;
    ss(root->left);
    if(root->left&&root->left->val==0&&!root->left->left&&!root->left->right)
        root->left=NULL;
}
struct TreeNode* pruneTree(struct TreeNode* root){
    ss(root);
    return root;
}
```
