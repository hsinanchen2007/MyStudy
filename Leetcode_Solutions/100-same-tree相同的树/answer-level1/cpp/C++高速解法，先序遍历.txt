class Solution {
public:
     bool isSameTree(TreeNode* p, TreeNode* q) {
        int mark=1;
        return preOrderCmp(p,q,mark);
    }

    bool preOrderCmp(TreeNode* p,TreeNode* q,int &mark){

       if((p==NULL&&q!=NULL)||(p!=NULL&&q==NULL)){ //只有一个为空
           mark=0;
           return mark;
       }

       if(p!=NULL&&q!=NULL){  //当前节点不为空
         if(p->val!=q->val){
            mark=0;
            return mark;
         }

         preOrderCmp(p->left,q->left,mark);
         preOrderCmp(p->right,q->right,mark);
       }
       return mark;
    }
    
};