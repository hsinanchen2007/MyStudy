step 代表当前步数
dp[i][j] 代表两个点分别在 grid[i][step-i]   和   grid[j][step-j]
然后从后往前找    不用记录 step 的状态

```C++ []
class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int N = grid.size(), n = 2*grid.size();
        if(N == 1) return grid[0][0];
        vector<vector<int>> dp(N, vector<int>(N, -1));
        dp[0][0] = grid[0][0];
        for(int step=1; step<n; step++)
            for(int i=min(step, N-1); i>=0; i--){
                // i 是递减的，后面的肯定也不满足，跳出此层循环，回到外层
                if(step-i >= N) break;
                for(int j=min(step, N-1); j>=0; j--){
                    if(step-j >= N) break;
                    int k = step-i, l = step-j, tem = dp[i][j];
                    // 当前路走不通
                    if(grid[i][k] < 0 || grid[j][l] < 0) {
                        dp[i][j] = -1;
                        continue ;
                    }
                    if(i > 0) tem = max(tem, dp[i-1][j]);
                    if(j > 0) tem = max(tem, dp[i][j-1]);
                    if(i > 0 && j > 0) tem = max(tem, dp[i-1][j-1]);
                    // 通过 tem 来判断当前路是否能走通   加上当前点的樱桃   判断是否同一点
                    if(tem >= 0) dp[i][j] = tem + grid[i][k] + (i==j ? 0 : grid[j][l]);
                    // cout<<i<<" "<<j<<" "<<dp[i][j]<<endl;
                }
            }
        return max(0, dp[N-1][N-1]);
    }
};
```
