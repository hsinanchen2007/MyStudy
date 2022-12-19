二叉树按层遍历，将每层的最后一个元素保存到返回数组里面即可
```
vector<int> rightSideView(TreeNode* root) {
        if(!root) return {};
        queue<TreeNode*> que;
        que.push(root);
        vector<int> ans;
        while(!que.empty())
        {
            int cnt = que.size();
            while(cnt--)  // 控制层
            {
                TreeNode* curr = que.front(); que.pop();
                if(cnt == 0) // 这是这层的最后一个节点
                {
                    ans.push_back(curr->val);
                }
                if(curr->left) que.push(curr->left);
                if(curr->right) que.push(curr->right);
            }
        }
        return ans;
    }
```
