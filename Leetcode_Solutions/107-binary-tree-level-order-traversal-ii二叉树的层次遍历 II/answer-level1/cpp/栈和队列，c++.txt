```
class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> ans;
        stack<vector<int>> st;
        vector<int> tmp;
        queue<TreeNode*> q;

        if(root==NULL)return ans;
        int cur=1,nextcur=0; 
        q.push(root);
        
        while(!q.empty())
        {
            TreeNode* l=q.front();
            tmp.push_back(l->val);
            q.pop();
            cur--;
            if(l->left)
            {
                q.push(l->left);
                nextcur++;
            }
            if(l->right)
            {
                q.push(l->right);
                nextcur++;
            }
            if(cur==0)
            {
                st.push(tmp);
                tmp.clear();
                cur=nextcur;
                nextcur=0;
            }
        }
        while(!st.empty())
        {
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
    }
};
```
