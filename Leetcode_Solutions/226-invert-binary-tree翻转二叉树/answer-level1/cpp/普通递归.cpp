左子树是翻转后的右子树，右子树是翻转后的左子树。
```C++ []
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(root){
            TreeNode* tmp;
            tmp=root->right;
            root->right=root->left;
            root->left=tmp;
            root->left=invertTree(root->left);
            root->right=invertTree(root->right);
        }
        return root;
    }
};
```
