```
vector<int> largestValues(TreeNode* root) {
        if(root==nullptr)
            return {};
        queue<pair<TreeNode*,int>> q;
        q.push(make_pair(root,0));
        vector<int> ans;
        int maxVal=INT_MIN;
        while(!q.empty())
        {
            TreeNode* cur=q.front().first;
            int c=q.front().second;
            if(cur->val>maxVal)
                maxVal=cur->val;
            q.pop();
            if(cur->left!=nullptr)
                q.push(make_pair(cur->left,c+1));
            if(cur->right!=nullptr)
                q.push(make_pair(cur->right,c+1));
            if(q.empty() || c!=q.front().second)
            {
                ans.push_back(maxVal);
                maxVal=INT_MIN;
            }
        }
        return ans;
    }
```
