我看题解中的大多数的动态规划都是建立m*n个数的二维数组，
每次遍历时，若 a[i][j]==1 则将dp[j]置0；
但是大家仔细想想，每个数的路径个数都是从上面或者左边来的，对于dp[j] （j!=0）来说，每次更新的时候 dp[j]  = dp[j-1]（*左边*）+dp[j]（*上面*） 即可，
对于j==0的情况（也就是最左侧），dp[j]不变即可。


```
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        vector<long long> dp(obstacleGrid[0].size(),0);
        dp[0] = 1;
        for (int i=0;i<obstacleGrid.size();i++){
            for (int j =0; j<dp.size();j++){
                if(obstacleGrid[i][j]==1) dp[j] = 0;
                else if(j==0 && i!=0) dp[j] = dp[j];
                else if(j!=0) dp[j] = dp[j]+dp[j-1];
            }
        }
        return dp[dp.size()-1];
    }
};
```
执行结果：
通过
显示详情
执行用时 :4 ms, 在所有 C++ 提交中击败了86.41% 的用户
内存消耗 :8.1 MB, 在所有 C++ 提交中击败了100.00%的用户