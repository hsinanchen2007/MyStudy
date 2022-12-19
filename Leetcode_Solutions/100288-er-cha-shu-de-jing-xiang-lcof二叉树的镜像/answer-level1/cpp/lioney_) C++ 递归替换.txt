```
class Solution {
public:
    TreeNode* mirrorTree(TreeNode* root) {
        if(!root) return nullptr;
        TreeNode* tLeft = mirrorTree(root->left);
        TreeNode* tRight = mirrorTree(root->right);
        TreeNode* tmp = root->left;
        root->left = tRight;
        root->right = tmp;
        return root;
    }
};
```
