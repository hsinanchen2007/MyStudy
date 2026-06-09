```
bool judgetree(struct TreeNode *a,struct TreeNode *b){
    if ((a == NULL&&b != NULL)||(a !=NULL &&b == NULL)) {
        return false;
    }
    if (a == NULL && b == NULL) {
        return true;
    }
    if (a->val != b->val){
        return false;
    }else{
        return (judgetree(a->left,b->left)&&judgetree(a->right,b->right));
    }
}

bool isSameTree(struct TreeNode* p, struct TreeNode* q){
    return judgetree(p,q);
}
```
