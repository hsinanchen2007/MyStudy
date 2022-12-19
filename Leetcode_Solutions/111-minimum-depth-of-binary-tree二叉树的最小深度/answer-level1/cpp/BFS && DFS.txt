```
// BFS
    int minDepth(TreeNode* root) {
        if(!root) return 0;
        queue<TreeNode*> que;
        que.push(root);
        int level = 1;
        int lenLeve = 1;
        while(!que.empty())
        {
            TreeNode * curr = que.front();
            que.pop();
            lenLeve--;
            // 该节点为叶子节点
            if(!curr->left && !curr->right)
                break;
            if(curr->left) que.push(curr->left);
            if(curr->right) que.push(curr->right);
            if(lenLeve == 0)
            {
                lenLeve=que.size();
                level++;
            }
            
        }
        return level;
    }
    // DFS
    int ans = INT_MAX;
    int minDepth(TreeNode* root)
    {
        if(!root) return 0;
        dfs(root,1);
        return ans;
    }
    void dfs(TreeNode* root, int level)
    {
        if(!root->right && !root->left)
        {
            ans = min(ans, level);
        }
        if(root->left) dfs(root->left, level+1);
        if(root->right) dfs(root->right, level+1);
    }
```
