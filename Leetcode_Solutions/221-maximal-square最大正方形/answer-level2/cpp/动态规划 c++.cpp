刚开始写了很多if else语句，结果还是漏了一些情况
后来才发现取三者最小+1就可以表示当前最大正方形的边长
动态规划的题还是得多做，做多了就有感觉了

```
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m=matrix.size();
        if(m==0) return 0;
        int n=matrix[0].size();
        int res=0;
        vector<vector<int>> dp(m+1,vector<int>(n+1,0));
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(matrix[i-1][j-1]=='1'){
                    dp[i][j]=min(min(dp[i-1][j-1],dp[i][j-1]),dp[i-1][j])+1;
                    res=max(res,dp[i][j]);
                }
            }
        }
        return res*res;
    }
};
```
