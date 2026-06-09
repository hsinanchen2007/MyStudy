### 解题思路
在每个坐标下计算左边一格和上面一格的走法，遇到障碍时走法为0
不过我不太明白为啥走法能超过int最大值  最后返回还在int之内

### 代码

```cpp
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size(),m = obstacleGrid[0].size();
        vector<vector<long long>> dp(n,vector<long long>(m,0));
        if(obstacleGrid[0][0])
        return  0;
        dp[0][0] = 1;
        for(int i=0;i<n;i++)
        for(int j=0;j<m;j++){
            if(obstacleGrid[i][j])
            continue;
            if(j>0)
             dp[i][j]+=dp[i][j-1];
             if(i>0)
             dp[i][j]+=dp[i-1][j];
        }
        return dp[n-1][m-1];
    }
};
```