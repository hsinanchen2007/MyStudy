1. 刚开始用dfs实现，发现超时了。
2. 后来用动态规划实现即可，递推公式dp[i][j]代表节点从i到j所能构成的非叶节点的最小和 dp[i][j] = max(dp[i][j],dp[i][k] + dp[k+1][j] + max[i][k]*max[k+1][j]);
3. 动态规划不是很难。
```
class Solution {
public:
    
    int mctFromLeafValues(vector<int>& arr) {
        int n = arr.size();
        vector<vector<int>> mx(n,vector<int>(n,0));
        vector<vector<int>> dp(n,vector<int>(n,INT_MAX));
        
        for(int i = 0;i < n; ++i){
            int m = arr[i];
            for(int j = i;j < n; ++j){
                m = max(m,arr[j]);
                mx[i][j] = m;
            }
        }
        /*initial*/
        for(int i = 0;i < n; ++i){
            dp[i][i] = 0;
        }
        for(int i = 0;i < n-1; ++i){
            dp[i][i+1] = arr[i]*arr[i+1];
        }
        /*dp*/
        for(int i = 2;i <= n; ++i){
            for(int j = 0;i+j < n; ++j){
                for(int k = j; k < i+j; ++k){
                    dp[j][j+i] = min(dp[j][j+i],dp[j][k]+dp[k+1][i+j]+mx[j][k]*mx[k+1][i+j]);
                }
            }
        }
        
        return dp[0][n-1];
    }
};
```