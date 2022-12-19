用递归即可解决。
```c
bool isSameTree(struct TreeNode* p, struct TreeNode* q){
    if(p==0&&q==0) return 1;
    else if(p&&q&&p->val==q->val) return isSameTree(p->left,q->left)&&isSameTree(p->right,q->right);
    return 0;
}
```