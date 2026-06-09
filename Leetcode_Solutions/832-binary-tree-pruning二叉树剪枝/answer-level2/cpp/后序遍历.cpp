```
class Solution {
public:
    TreeNode* pruneTree(TreeNode* root) {
        if(root==nullptr)return nullptr;
        root->left=pruneTree(root->left);
        root->right=pruneTree(root->right);
        return (root->left==nullptr && root->right==nullptr && root->val==0)?nullptr:root;
    }
};
```
