### 解题思路
整体思路与不同路径1类似，都是采用动态规划的方法，不同是在于边界的初始化上。
这里对初始值的判断可能提升了较大的运行效率，当然不判断结果也是正确的。
![image.png](https://pic.leetcode-cn.com/51351e53d430ec1374a4db04deab3c2e612562041a3d6de478cf08a0289cc8e9-image.png)


### 代码

```cpp
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if(obstacleGrid[0][0]==1){
            return 0;
        }
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        long dp[m][n];
        memset(dp, 0, m*n);
        for(int i=0;i<m;i++){
            if(obstacleGrid[i][0]!=1){
                dp[i][0] = 1;
            }
            else{
                for(int j=i;j<m;j++){
                    dp[j][0] = 0;
                }
                break;
            }
        }
        for(int j=0;j<n;j++){
            if(obstacleGrid[0][j]!=1){
                dp[0][j] = 1;
            }
            else{
                for(int i=j;i<n;i++){
                    dp[0][i] = 0;
                }
                break;
            }
        }
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                if(obstacleGrid[i][j]==1){
                    dp[i][j] = 0;
                }
                else{
                    dp[i][j] = dp[i-1][j]+dp[i][j-1];
                }
            }
        }
        return dp[m-1][n-1];
    }
};

```