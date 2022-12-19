搜索树性质：val(左子树的任意点)<val(根)<val(右子树的任意点)  
dp[i]表示i个节点的搜索树数目，左子树分配j个点，右子树分配i-1-j个点，两边子树都是子问题    
复杂度O(n^2)(其实可以On)
```
class Solution {
public:
    
    int numTrees(int n) {
        vector<int>dp(n+1,0);
        dp[0]=dp[1]=1;int ans=0;
        ans=dfs(n,dp);
        return ans;
    }
    int dfs(int n,vector<int>&dp){
        if(dp[n])return dp[n];
        int tp=0;
        for(int i=0;i<=n-1;i++){
            tp+=dfs(i,dp)*dfs(n-1-i,dp);
        }
        return dp[n]=tp;
    }
};
```