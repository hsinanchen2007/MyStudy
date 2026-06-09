执行用时 :8 ms, 在所有 cpp 提交中击败了57.12%的用户
内存消耗 :8.9 MB, 在所有 cpp 提交中击败了97.84%的用户

```
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        const size_t m = obstacleGrid.size(), n = obstacleGrid[0].size();
        if (obstacleGrid[0][0] == 1) return 0;

        //定义dp，注意采用long int，否则会抛出overflow异常
        long int dp[m][n]={1};

        //初始化dp第一列
        for(int i=1; i<m; i++) {
            if ((dp[i-1][0]) == 0 || (obstacleGrid[i][0] == 1)) 
                dp[i][0] = 0;   
            else
                dp[i][0] = 1;
        }
        //初始化dp第一行 
        for(int i=1; i<n; i++) {
            if ((dp[0][i-1]) == 0 || (obstacleGrid[0][i] == 1)) 
                dp[0][i] = 0;   
            else
                dp[0][i] = 1;
        }

        //更新dp
        for(int i=1; i<m; i++) {
            for(int j=1; j<n; j++) {
                if (obstacleGrid[i][j] == 1) 
                    dp[i][j] = 0;
                else 
                    dp[i][j] = dp[i-1][j] + dp[i][j-1];
                
            }
        }
        /*
        for(int i=0; i<m; i++){ 
            for(int j=0; j<n; j++)
                cout << dp[i][j] <<'\t';
            cout << '\n';
        }
        */
        return dp[m-1][n-1];  
    }
};
```
