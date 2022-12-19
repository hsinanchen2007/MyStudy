没有使用队列，菜鸟，对队列还不熟
```
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ret;
        if(root == nullptr)
            return ret;
        
        vector<TreeNode*> tree;
        vector<TreeNode*> treebak;
        vector<int> tmp;
        tree.push_back(root);
        treebak = tree;

        while(tree.size()>0)
        {
            tree.clear();
            tmp.clear();
            for(auto node:treebak)
            {
                tmp.push_back(node->val);
                if(node->left != nullptr) tree.push_back(node->left);
                if(node->right != nullptr) tree.push_back(node->right);
            }
            treebak = tree;
            ret.push_back(tmp);
        }
        return ret;
    }
```