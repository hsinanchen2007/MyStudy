```
    vector<int> levelOrder(TreeNode* root) {
        if(!root)   return {};
        vector<int> ans;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            TreeNode *s = q.front();
            q.pop();
            ans.push_back(s->val);
            if(s->left!=NULL)   q.push(s->left);
            if(s->right!=NULL)  q.push(s->right);
        }
        return ans;
    }
```