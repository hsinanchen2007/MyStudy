### 解题思路

DP

### 代码

```cpp
class Solution {
public:
    int tilingRectangle(int n, int m) {
        vector<vector<int>> dp(14, vector<int>(14));
        
        for(int i=0; i<=n; i++)
            dp[i][0] = 0;
        for(int i=0; i<=m; i++)
            dp[0][i] = 0;
        
        for(int i=1; i<=n; i++)
            for(int j=1; j<=m; j++) {
                dp[i][j] = INT_MAX;
                if(i == j) {
                    dp[i][j] = 1;
                    continue;
                } 
                // 横切
                for(int r=1; r<=i/2; r++) {
                    dp[i][j] = min(dp[i][j], dp[r][j] + dp[i - r][j]);
                }
                // 竖切
                for(int c=1; c<=j/2; c++) {
                    dp[i][j] = min(dp[i][j], dp[i][c] + dp[i][j - c]);
                }
                // 中心一个单元格
                for(int p=1; p<=i; p++)
                    for(int q=1; q<=j; q++) {
                        dp[i][j] = min(dp[i][j], 1 + dp[p-1][q] + dp[i-p+1][q-1] + dp[i-p][j-q+1] + dp[p][j-q]);
                    }
            }
        return dp[n][m];
    }
};
```