```
    void flatten(TreeNode* root) {
        dfs(root);
    }

    TreeNode* dfs(TreeNode* &root)
    {
        if(root == NULL)
            return root;
        dfs(root->left);
        TreeNode* rr = root->right;
        if(root->left && root->right)
        {
            root->right = root->left;
            TreeNode* cur = root->right;
            while(cur->right)
            {
                cur = cur->right;
            }
            cur->right = rr;
            root->left = NULL;
        }
        if(root->left && root->right == NULL)
        {
            root->right = root->left;
            root->left = NULL;
        }
        dfs(root->right);
        return root;
    }
```
