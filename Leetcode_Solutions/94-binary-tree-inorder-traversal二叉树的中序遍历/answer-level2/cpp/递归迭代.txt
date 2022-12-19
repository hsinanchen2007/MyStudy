简单的C++解法
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
       
        if (root==NULL){return pnext;}
        else {
            inorderTraversal(root->left);
        pnext.push_back(root->val);
        inorderTraversal(root->right);}
       
        return pnext;
    
    }
private:
     vector<int> pnext;
};
