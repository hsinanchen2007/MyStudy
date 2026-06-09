### 解题思路
注：一定要long类型，int会溢出
处理障碍时将dp[i][j]=0;
### 代码

```cpp
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        // 有障碍物 0,1
        // 状态表示dp[i][j] 表示i,j位置有多少条路径
        // 状态递归 dp[i][j]=dp[i-1][j]+dp[i][j-1] 
        // 向下或者向右
        // 求有多少条路径
        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();
        vector<long> a(n,0);
        vector<vector<long>> dp(m,a);
        if(m==0) return 0;
        if(m==1&&n==1){
            if(obstacleGrid[0][0]) return 0;
            else return 1;
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(obstacleGrid[i][j]==1) dp[i][j]=0;
                else if(obstacleGrid[i][j]==0){
                    if(i==0&&j==0) dp[i][j]=1;
                    else if(i==0) dp[i][j]=dp[i][j-1];
                    else if(j==0) dp[i][j]=dp[i-1][j];
                    else dp[i][j]=dp[i-1][j]+dp[i][j-1];
                }
            }
        }
        return dp[m-1][n-1];
    }
};
```