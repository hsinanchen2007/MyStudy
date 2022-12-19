

    TreeNode* bstToGst(TreeNode* root) {
        if(root == nullptr)
            return nullptr;

        TreeNode* tmp = root;
        stack<TreeNode*> s;
        int res = 0;

        while(tmp || !s.empty())
        {
            if(tmp)
            {
                s.push(tmp);
                tmp = tmp->right;
            }
            else
            {
                tmp = s.top();
                s.pop();

                tmp->val += res;
                res = tmp->val;

                tmp = tmp->left;
            }
        }
        return root;
    }
