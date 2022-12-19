```
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
       if((p!=NULL&&q==NULL)||(p==NULL&&q!=NULL))//存在一方为空 另一方不为空的情况  
           return false;
        else if(p==NULL&&q==NULL);
        else if(p!=NULL&&q!=NULL){//在使用指针之前 确保它不为空
            if(p->val!=q->val)
                return false;
            if(p->left!=NULL&&q->left!=NULL){
                if(!isSameTree(p->left,q->left))
                    return false;
                }
            else if((p->left!=NULL&&q->left==NULL)||(p->left==NULL&&q->left!=NULL))
                return false;
             if(p->right!=NULL&&q->right!=NULL){
                 if(!isSameTree(p->right,q->right))
                     return false;
             }
            else if((p->right!=NULL&&q->right==NULL)||(p->right==NULL&&q->right!=NULL))
                return false;
        }
        return true;
        }
};
```
