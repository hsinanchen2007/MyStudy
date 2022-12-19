### 解题思路
    与62题思路相近，小白一枚，代码写的有点啰嗦，欢迎大佬指教。
    生成一个M*N二维数组dp，这里用二维vector表示，dp的含义是从此位置到终点的走法。
    在给dp赋值时，要注意给出的矩阵中元素为1的点的处理。
    由于测试的时候数据可能会越界，所以这里把函数的返回值改成了double。

### 代码

```cpp
class Solution {
public:
    double uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();
        vector<vector<double>> dp;
        for(int i=0;i<m;i++)
        {
            vector<double> tmp;
            for(int j=0;j<n;j++)
            {
                tmp.push_back(0);
            }
            dp.push_back(tmp);
        }
        for(int i=m-1;i>=0;i--)
        {
            for(int j=n-1;j>=0;j--)
            {
                if(obstacleGrid[i][j]==1)
                    dp[i][j]=0;
                else if(i==m-1&&j==n-1)dp[i][j]=1;
                else if(i==m-1)dp[i][j]=dp[i][j+1];
                else if(j==n-1)dp[i][j]=dp[i+1][j];
                else dp[i][j]=dp[i+1][j]+dp[i][j+1];
            }
        }
        return dp[0][0];
    }
};
```