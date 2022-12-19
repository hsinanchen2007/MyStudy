使用一个队列进行存储节点


```
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if(root==NULL||(root->left==NULL&&root->right==NULL))
            return true;
        if((root->left!=NULL&&root->right==NULL)||(root->left==NULL&&root->right!=NULL))
            return false;
        else
        {
            if(root->left->val!=root->right->val)
                return false;
        }
        queue<TreeNode*> s;
        TreeNode* p;
        TreeNode* q;
        p=root->left;
        q=root->right;
        s.push(p);
        s.push(q);
        while(s.size())
        {
            p=s.front();
            s.pop();
            q=s.front();
            s.pop();
            if(p->left!=NULL&&q->right!=NULL){
                if(p->left->val==q->right->val)
                {
                    s.push(p->left);
                    s.push(q->right);
                }
                else
                {
                    return false;
                }
            }
            else if((p->left!=NULL&&q->right==NULL)||(p->left==NULL&&q->right!=NULL))
            {
                return false;
            }

            if(p->right!=NULL&&q->left!=NULL){
                if(p->right->val==q->left->val)
                {
                    s.push(p->right);
                    s.push(q->left);
                }
                else
                {
                    return false;
                }
            }
            else if((p->right!=NULL&&q->left==NULL)||(p->right==NULL&&q->left!=NULL))
            {
                return false;
            }    
        }
        return true;
    }
};
```
        
