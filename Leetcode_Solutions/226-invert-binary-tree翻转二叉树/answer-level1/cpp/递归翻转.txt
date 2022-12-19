```
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        TreeNode* temp;
        if(root==NULL){return NULL;}
       temp=root->left;root->left=root->right;root->right=temp;
        invertTree(root->left);
        invertTree(root->right);
        return  root; 
    }
};
```
