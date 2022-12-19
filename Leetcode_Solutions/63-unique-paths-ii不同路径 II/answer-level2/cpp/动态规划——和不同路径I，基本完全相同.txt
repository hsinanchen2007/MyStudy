和62题基本完全相同，只是在做选择时，需要对障碍物处理下即可。
状态转移方程大体上仍为 dp[i][j] = dp[i - 1][j] + dp[i][j - 1]
只不过如果当前位置是障碍物，就直接将dp[i][j] = 0即可。
唯一要注意的就是int类型会上溢出，所以需要用long long 或者 unsigned int。
```
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();
        vector<vector<unsigned int>> dp(n,vector<unsigned int>(m,0));

        for(int i = 0;i < n;i++){
            for(int j = 0;j < m;j++){
                
                if(obstacleGrid[i][j]){
                    dp[i][j] = 0;
                    continue;
                }
                if(i == 0 && j == 0){
                    dp[i][j] = 1;
                }
                if(i > 0){
                  
                        dp[i][j] += dp[i - 1][j];
                
                }
                if(j > 0){

                        dp[i][j] += dp[i][j - 1];
                    
                }
            }
        }
        return dp[n - 1][m - 1];
    }
};
```

优化的思路和之前62题一样
```
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();
        vector<long long> dp(m,0);

        for(int i = 0;i < n;i++){
            for(int j = 0;j < m;j++){
                unsigned int a = 0,b = 0;
                if(obstacleGrid[i][j]){
                    dp[j] = 0;
                    continue;
                }
                else
                {
                    if(i == 0 && j == 0){
                        dp[j] = 1;
                    }
                    else{
                        if(i > 0){
                            a = dp[j];    
                            
                        }
                        if(j > 0){
                            b = dp[j - 1];
                            
                        }
                        dp[j] = a + b;
                    }
                }
            }
        }
        return dp[m - 1];
    }
};
```


