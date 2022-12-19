```
class Solution {
public:
    TreeNode* trimBST(TreeNode* root, int L, int R) {
        if(root == NULL)
        {
            return NULL;
        }
        if(R < root->val)
        {
            return trimBST(root->left, L, R);
        }
        else if(L > root->val)
        {
            return trimBST(root->right, L, R);
        }
        else
        {
            root->left = trimBST(root->left, L, root->val);
            root->right = trimBST(root->right, root->val, R);
            return root;
        }
    }
};
```
