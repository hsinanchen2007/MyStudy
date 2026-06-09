### 解题思路
注意：dp数组的中间值可能会出现大于int范围的数，将dp声明为long类型即可。

### 代码

```cpp
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if(obstacleGrid[0][0] == 1) return 0;
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<long>> dp(m+1, vector<long>(n+1, 0));
        dp[1][1] = 1;
        for(int i=1; i<m+1; i++){
            for(int j=1; j<n+1; j++){
                if(!(i==1 && j==1)){
                    if(obstacleGrid[i-1][j-1] == 1)  dp[i][j] = 0;
                    else{
                        dp[i][j] = dp[i-1][j] + dp[i][j-1];
                    }    
                }
            }
        }
        return dp[m][n];  //1637984640
    }
};
```