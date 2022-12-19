`
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if(!root)return true;
        if(!root->left&&!root->right)return true;
        if(!root->left||!root->right)return false;
        queue<TreeNode*>left;
        stack<TreeNode*> right,temp;
        left.push(root->left);
        right.push(root->right);
        while(!left.empty()&&!right.empty()){
            int size=left.size();
            int count=0;
            while(size-->0){
                TreeNode* a=left.front(),*b=right.top();
                left.pop();
                right.pop();
                if(a->val!=b->val)return false;
                if(a->left!=NULL^b->right!=NULL)
                {             
                    return false;
                }
                if(a->right!=NULL^b->left!=NULL)
                {             
                    return false;
                }
                if(a->left){
                    left.push(a->left);
                    temp.push(b->right);
                }
                if(b->left){
                    left.push(a->right);
                    temp.push(b->left);
                }
            }
            while(!temp.empty()){
                right.push(temp.top());
                temp.pop();
            }
        }
        return true;
    }
};
`