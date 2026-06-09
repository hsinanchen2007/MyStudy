思路：首先要明白删除节点的规则，如果用前序遍历，则每一次都要检查所有的子树，如果用后序遍历则简单得多，只需要如果当前节点为0且为叶子节点即可删除。
 TreeNode* pruneTree(TreeNode* root) {
        if(root==nullptr)
            return nullptr;
         TreeNode* p=root;
       
        p->right=pruneTree(p->right);
        p->left=pruneTree(p->left);
       if(p->val==0&&p->right==nullptr&&p->left==nullptr)
           p=nullptr;
        return p;
        
    }