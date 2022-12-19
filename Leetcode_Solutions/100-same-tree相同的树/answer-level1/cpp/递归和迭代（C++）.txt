**1.递归**  
```
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p==NULL&&q==NULL)return true;
        if(p==NULL&&q!=NULL)return false;
        if(p!=NULL&&q==NULL)return false;
        if(p->val!=q->val)return false;
        return isSameTree(p->left,q->left)&&isSameTree(p->right,q->right);
    }
};
```
**2.迭代**  
```
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        stack<TreeNode*> S;
        S.push(q);
        S.push(p);
        TreeNode* p_temp;
        TreeNode* q_temp;
        while(!S.empty()){
            p_temp=S.top();
            S.pop();
            q_temp=S.top();
            S.pop();
            if(p_temp==NULL&&q_temp==NULL)continue;
            else if(p_temp!=NULL&&q_temp==NULL)return false;
            else if(p_temp==NULL&&q_temp!=NULL)return false;
            else if(p_temp->val!=q_temp->val)return false;
            else{
                S.push(q_temp->right);
                S.push(p_temp->right);
                S.push(q_temp->left);
                S.push(p_temp->left);
            }
        }
        return true;
    }
};
```