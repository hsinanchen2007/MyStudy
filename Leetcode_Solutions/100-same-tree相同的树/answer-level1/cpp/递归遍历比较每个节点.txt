//递归比较每个节点

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p==NULL && q==NULL)
        {
            return  true;
        }
        if(p==NULL  && q!=NULL)
        {
            return false;
        }
        if(p!=NULL  && q==NULL)
        {
            return false;
        }
        if(p!=NULL && q!=NULL && p->val!=q->val)
        {
            return false;
        }
    
        return isSameTree(p->left,q->left) && isSameTree(p->right,q->right);  
    }
};