bool isSameTree(struct TreeNode* p, struct TreeNode* q){
//前序遍历
    if(p!=NULL&&q!=NULL){
        if(p->val!=q->val) return false;
        if(isSameTree(p->left,q->left))
            if(isSameTree(p->right,q->right))
                    return true;
        return false;
    }
    
    if(p==NULL&&q==NULL) return true;
    else return false;
}