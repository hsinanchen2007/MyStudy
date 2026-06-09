```
    vector<int> postorderTraversal(TreeNode* root)
    {
        vector<int> res;
        TreeNode* curr = root;
        TreeNode* pre;
        while(curr!=NULL)
        {
            res.push_back(curr->val);
            if(curr->left != NULL && curr->right != NULL)
            {
                pre = curr->right;
                while(pre->left != NULL)
                    pre = pre->left;
                pre->left = curr->left;
                TreeNode* tmp = curr;
                curr = curr->right;
                tmp->left = NULL;
            }
            else
            {
                curr = curr->left != NULL ? curr->left : curr->right;
            }    
        }
        reverse(res.begin(), res.end());
        return res;
    }
```
