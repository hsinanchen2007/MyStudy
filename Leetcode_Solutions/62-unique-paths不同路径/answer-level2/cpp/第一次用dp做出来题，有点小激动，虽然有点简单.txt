```
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m,vector<int>(n,0));//用一个二维数组，dp[i][j]代表从起点到（i，j）的走路方式
        for(int i=0;i<n;i++) dp[0][i]=1;//到第一行与第一列的所有点只有一种走法。
        for(int i=0;i<m;i++) dp[i][0]=1;
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                dp[i][j] = dp[i-1][j]+dp[i][j-1];//而他俩之间夹的那个点就有是这两种可能相加
            }
        }
        return dp[m-1][n-1];
    }
};
```
