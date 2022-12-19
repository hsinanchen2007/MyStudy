```
struct TreeNode* mergeTrees(struct TreeNode* t1, struct TreeNode* t2){
    if(!t1&&!t2) return 0;
    if(!t1) return t2; //避空
    if(!t2) return t1;
    struct TreeNode *root=(struct TreeNode *)malloc(sizeof(struct TreeNode)); //新建一个返回节点
    root->val=t1->val+t2->val; //值为二者之和
    root->left=mergeTrees(t1->left,t2->left);
    root->right=mergeTrees(t1->right,t2->right);
    return root;
}
```
