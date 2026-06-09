```
class Solution {
public:
    vector<int>result;
    void postorder(TreeNode* root,vector<int>&result){
        if(root==NULL) return;
         if(root->left==NULL&&root->right==NULL){
             result.push_back(root->val);
        }else{
            postorder(root->left,result);
            postorder(root->right,result);
            result.push_back(root->val);
        }
    }
    vector<int> postorderTraversal(TreeNode* root) {
        postorder(root,result);
        return result;
    }
};
```
