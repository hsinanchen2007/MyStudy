```
class Solution {
public:
    int sumNumbers(TreeNode* root) {
        int res = 0;
        if(root == NULL)
            return 0;
        sumsub(root, 0, res);
        return res;
    }
    void sumsub(TreeNode* root, int pre, int& res)
    {
        if(root->left == NULL && root->right == NULL)
        {
            res += pre*10+root->val;
        }
        else
        {
            if(root->left != NULL)
            {
                sumsub(root->left, pre*10+root->val, res);
            }
            if(root->right != NULL)
            {
                sumsub(root->right, pre*10+root->val, res);
            }
        }
    }
};
```
