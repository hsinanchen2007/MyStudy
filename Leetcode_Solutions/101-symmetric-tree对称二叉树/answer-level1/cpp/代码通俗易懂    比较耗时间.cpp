```
class Solution {
public:
    bool fun(TreeNode *Left,TreeNode*Right){
        if(Left==NULL&&Right==NULL)
            return true;
        else if((Left!=NULL&&Right==NULL)||(Left==NULL&&Right!=NULL))
                return false;
        else{
            if(Left->val==Right->val){
                if(!fun(Left->left,Right->right))
                    return false;
                if(!fun(Left->right,Right->left))
                    return false;                
            }else{
                return false;
                
            }
        }
        return true;
    }
    bool isSymmetric(TreeNode* root) {
        if(root==NULL)
            return true;
        return fun(root->left,root->right);
    }
};
```
