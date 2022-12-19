看了许多都是从左到右的后序遍历，这里有一个从右向左的版本
class Solution {
public:
    TreeNode *pre=NULL;
    void flatten(TreeNode* root){
        if(root==NULL) return ;
        flatten(root->right);
        flatten(root->left);
        root->right=pre;
        root->left=NULL;
        pre=root;
    }
};