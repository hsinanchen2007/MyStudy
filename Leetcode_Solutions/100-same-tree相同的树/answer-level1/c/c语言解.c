```
bool isSameTree(struct TreeNode* p, struct TreeNode* q){
    return p==NULL||q==NULL?p==NULL&&q==NULL:p->val==q->val?isSameTree(p->left,q->left)&&isSameTree(p->right,q->right):false;
}
```
