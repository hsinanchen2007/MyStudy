```
class Solution {
public:
    TreeNode* increasingBST(TreeNode* root) {
        TreeNode* r = NULL;
        if(root == NULL)
        {
            return NULL;
        }
        root->right = increasingBST(root->right);
        if(root->left)
        {
            TreeNode* l = increasingBST(root->left);
            r = l;
            while(r->right != NULL)
            {
                r = r->right;
            }
            r->right = root;
            root->left = NULL;
            root = l;
        }
        return root;
    }
};
```
