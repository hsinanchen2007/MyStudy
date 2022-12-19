```
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return helper(root, nullptr, nullptr);
    }
    bool helper(TreeNode* root, TreeNode* min, TreeNode* max) {
        if(!root) return true;
        if(min && min->val >= root->val || max && max->val <= root->val) return false;
        return helper(root->left, min, root) && helper(root->right, root, max);
    }
};
```
