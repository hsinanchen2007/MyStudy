踩坑：1、本来以为直接DFS就得了，结果发现超时。。。2、在DFS基础上去改，发现比较麻烦，没想到好的解法。

所以看题解了。。下面是题解的解法。
思路：因为机器人只能向右和向下，所以是不存在绕回原路的。
1、如果grid[0][0]==1, 那么直接返回0. 否则，dp[0][0]=1。
2、先处理第一行和第一列，从左到右扫描第一行，如果grid[0][j]==0, 有dp[0][j]=dp[0][j-1]. 
同理的从上到下扫描第一列， 如果grid[i][0]==0, 有dp[i][0]=dp[i-1[0]. 
3、开始处理中间的，继续逐行扫描，此时如果grid[i][j]]==0, 有dp[i][j]=dp[i-1[j] + dp[i][j-1].
4、结果是dp[R-1][C-1]

注意：dp的数据类型要用long，否则溢出

```
class Solution {
public:
    long dp[105][105];
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        long R = obstacleGrid.size();
        long C = obstacleGrid[0].size();
        
        if (obstacleGrid[0][0] == 1) {
            return 0;
        }
        
        dp[0][0] = 1;
        
        for (int i=1; i<R; i++) {
            dp[i][0] = (obstacleGrid[i][0] == 0 && dp[i - 1][0] == 1) ? 1 : 0;
        }
        
        for (int j=1; j<C; j++) {
            dp[0][j] = (obstacleGrid[0][j] == 0 && dp[0][j - 1] == 1) ? 1 : 0;
        }
        
        
        for (int i=1; i<R; i++) {
            for (int j=1; j<C; j++) {
                if (obstacleGrid[i][j] == 0 ) {
                    dp[i][j] = dp[i-1][j] + dp[i][j-1];
                } else {
                    dp[i][j] = 0;
                }
            }
        }
        
        
        return dp[R-1][C-1];
    }
};
``` 