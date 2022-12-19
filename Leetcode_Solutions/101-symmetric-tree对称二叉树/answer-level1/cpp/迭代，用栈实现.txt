```
    #include <iostream>
    using namespace std;
    #include <stack>
    class Solution {
    public:
        bool isSymmetric(TreeNode* root) {
            if(!root)return true;
            if(!root->left&&!root->right)return true;
            if(!root->left||!root->right)return false;

            TreeNode *p,*q;
            stack<TreeNode*>S;
            p=root->left;
            q=root->right;
            if(p->val!=q->val)return false;
            S.push(p);
            S.push(q);
            while(!S.empty())
            {
                TreeNode *temp1,*temp2;
                temp1=S.top();
                S.pop();
                temp2=S.top();
                S.pop();
                if(temp1==NULL&&temp2==NULL)continue;
                else if(temp1==NULL&&temp2!=NULL)return false;
                else if(temp1!=NULL&&temp2==NULL)return false;
                else if(temp1->val!=temp2->val)return false;
                else
                {
                    S.push(temp1->left);
                    S.push(temp2->right);
                    S.push(temp1->right);
                    S.push(temp2->left);
                }    
            }
            return true;
        }
    };
```
