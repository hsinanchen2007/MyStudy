
# BFS

```
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>>res;
        vector<int>ans;
        if(root==nullptr)return res;
        queue<TreeNode*>que;
        que.push(root);
        int start=0;
        int end=1;
        while(!que.empty()){
            start++;
            auto x=que.front();
            que.pop();
            ans.push_back(x->val);
            if(x->left){
                que.push(x->left);
            }
            if(x->right){
                que.push(x->right);
            }
            if(start==end){
                start=0;
                end=que.size();
                res.push_back(ans);
                ans.clear();
            }
        }
        return res;
    }
};

```
# DFS
```
class Solution {
public:
    void dfs(TreeNode* root,int depth,vector<vector<int>>&res){
        if(root==nullptr)return;
        if(depth==res.size())res.push_back(vector<int>());
        res[depth].push_back(root->val);
        dfs(root->left,depth+1,res);
        dfs(root->right,depth+1,res);
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>>res;
        dfs(root,0,res);
        return res;
    }
};
```