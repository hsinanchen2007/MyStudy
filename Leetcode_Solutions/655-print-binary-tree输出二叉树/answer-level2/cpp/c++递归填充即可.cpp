bfs+递归：
```
class Solution {
public:
    void dfs(TreeNode* root,vector<vector<string>>&ans,int x,int l,int r){
        int mid=(l+r)>>1;
        ans[x][mid]=to_string(root->val);
        if(root->left)dfs(root->left,ans,x+1,l,mid-1);
        if(root->right)dfs(root->right,ans,x+1,mid+1,r);
    }
    vector<vector<string>> printTree(TreeNode* root) {
        queue<TreeNode*>q;
        q.push(root);
        int len=0;
        while(!q.empty()){
           int size=q.size();
            for(int i=0;i<size;i++){
                TreeNode* node=q.front();
                q.pop();
               if(node->left)q.push(node->left);
               if(node->right)q.push(node->right);    
            }
            len++;
        }
        int m=pow(2,len)-1;
      vector<vector<string>>ans(len,vector<string>(m));
        dfs(root,ans,0,0,m-1);
        return ans;
    }
};
```
