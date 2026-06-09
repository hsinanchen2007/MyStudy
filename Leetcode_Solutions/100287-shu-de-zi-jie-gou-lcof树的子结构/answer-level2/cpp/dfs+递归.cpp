首先先序遍历A树，找到与B根节点相同的节点P，找不到返回false；
递归遍历B树是否和A子结构和值相同
class Solution {
public:
    bool issame(TreeNode* A, TreeNode* B){
        if(!A&&!B)return true;
        if(A&&!B)return true;
        if(!A&&B)return false;
        if(A->val!=B->val)return false;
        return issame(A->left,B->left)&&issame(A->right,B->right);
        
    }
    bool isSubStructure(TreeNode* A, TreeNode* B) {
        TreeNode*p=A;
        if(!B)return false;
        stack<TreeNode*>stack;
        int flag=0;
        while(p||!stack.empty()){
            while(p){
                if(p->val==B->val){
                    flag=1;
                    break;
                }
                stack.push(p);
                p=p->left;
            }
            if(flag==1)break;
            p=stack.top();
            stack.pop();
            p=p->right;
        }
        if(flag==0)return false;
        return issame(p,B);
    }
};