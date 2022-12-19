看大家基本都是递归解法，贴一个非递归的：

        stack<TreeNode*> tree_node;
        if(NULL == root) return 0;
        tree_node.push(root);
        int sum = 0;
        while (!tree_node.empty())
        {
            TreeNode* node = tree_node.top();
            tree_node.pop();

            if(node->left != NULL)
            {
                //判断一下是否为左叶子, 是左叶子就不用入栈了
                 if(node->left->left==NULL && node->left->right==NULL)
                 {
                     sum+=node->left->val;
                 }
                 else
                 {
                     tree_node.push(node->left);
                 }        
            }

            if(node->right != NULL)
            {
                tree_node.push(node->right);
            }
        }
        return sum;    