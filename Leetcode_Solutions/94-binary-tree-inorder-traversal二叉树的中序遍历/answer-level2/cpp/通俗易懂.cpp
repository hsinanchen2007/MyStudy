```
class Solution {
public:
    void fun1(TreeNode *root,vector<int>&res){
        if(root!=NULL){
            if(root->left!=NULL){
                fun1(root->left,res);
                        }
            res.push_back(root->val);
            if(root->right!=NULL){
                fun1(root->right,res);
              
            }
          }
    }

    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>res;
        fun1(root,res);
        return res;
    }
};
```
