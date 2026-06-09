跟二叉树的层序遍历一样，需要用queue来辅助，先把根节点排入队列中，然后从队中取出来，交换其左右节点，如果存在则分别将左右节点在排入队列中，以此类推直到队列中木有节点了停止循环，返回root即可
```
TreeNode* mirrorTree(TreeNode* root) {
        if (root == nullptr)
            return nullptr;
        
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty())
        {
            TreeNode* node = q.front();
            q.pop();
            if (node->left)
            q.push(node->left);
            if (node->right)
            q.push(node->right);
            swap(node->left, node->right);
        }
        return root;
    }
```
