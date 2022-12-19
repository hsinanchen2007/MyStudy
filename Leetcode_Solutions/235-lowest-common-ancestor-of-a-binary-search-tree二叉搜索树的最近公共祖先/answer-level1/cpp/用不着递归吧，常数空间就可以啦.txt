
```
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==nullptr || p==nullptr || q==nullptr)return nullptr;
        while(root){
            int diffp=p->val - root->val,diffq=q->val - root->val;
            if(diffp==0 ||diffq==0 || (diffp^diffq)<0)return root;
            root= diffp<0?root->left:root->right;
        }
        return nullptr;
    }
};
```
