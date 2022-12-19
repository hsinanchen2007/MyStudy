```
class Solution {
private:
    int ans=0;
public:
    int longestZigZag(TreeNode* root) {
        dfs(root->left,0,0);
        dfs(root->right,1,0);
        return ans;
    }
    void dfs(TreeNode* node,int i,int res){
        if(!node) {
            ans=max(res,ans);
            return;
        }
        if(i==0){
            dfs(node->right,1,res+1);
            dfs(node->left,0,0);
        }
        else{
            dfs(node->left,0,res+1);
            dfs(node->right,1,0);
        }
            
    }
};
```
