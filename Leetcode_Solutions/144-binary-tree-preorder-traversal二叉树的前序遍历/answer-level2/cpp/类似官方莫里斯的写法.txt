如果curr存在两个子节点，则把右节点接到左节点的最右节点的右端；如果只存在一个子节点，则直接选该子节点
```
    vector<int> preorderTraversal(TreeNode* root)
    {
        vector<int> res;
        TreeNode* curr = root;
        TreeNode* pre;
        while(curr!=NULL)
        {
            res.push_back(curr->val);
            if(curr->left != NULL && curr->right != NULL)
            {
                pre = curr->left;
                while(pre->right != NULL)
                    pre = pre->right;
                pre->right = curr->right;
                TreeNode* tmp = curr;
                curr = curr->left;
                tmp->left = NULL;
            }
            else
            {
                curr = curr->left != NULL ? curr->left : curr->right;
            }
        }
        return res;
    }
```
