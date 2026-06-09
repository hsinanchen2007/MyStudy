```
class Solution {
public:
    vector<int>result;
    void preorder(TreeNode* root,vector<int>&result){
        if(root==NULL)
            return;
        else{
            result.push_back(root->val);
            preorder(root->left,result);
            preorder(root->right,result);
        }
    }
    vector<int> preorderTraversal(TreeNode* root) {
        preorder(root,result);
        return result;
    }
};
```
