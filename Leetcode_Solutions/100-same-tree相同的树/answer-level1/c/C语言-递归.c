```
bool isSameTree(struct TreeNode* p, struct TreeNode* q){
    if(p == NULL && q == NULL){
        return true;
    }
    if(p != NULL && q != NULL && p->val == q->val){
        bool x = isSameTree(p->left,q->left);
        bool y = isSameTree(p->right,q->right);
        return x && y;
    }else{
        return false;
    }
}
```
