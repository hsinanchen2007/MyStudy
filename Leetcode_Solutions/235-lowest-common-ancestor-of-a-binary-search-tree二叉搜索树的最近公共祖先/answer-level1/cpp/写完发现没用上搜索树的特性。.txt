44ms,25.8MB
```
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if((root==p)||(root==q))return root;
        if(root==nullptr)return root;
        if((root->left==nullptr)&&(root->right==nullptr))return nullptr;
        TreeNode *al=lowestCommonAncestor(root->left,p,q),*ar=lowestCommonAncestor(root->right,p,q);
        if((al!=nullptr)&&(ar!=nullptr))return root;
        if(al==nullptr)return ar;
        return al;
    }
};
```