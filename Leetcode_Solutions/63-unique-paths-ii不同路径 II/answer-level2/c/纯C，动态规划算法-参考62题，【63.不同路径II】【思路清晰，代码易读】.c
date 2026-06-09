### 解题思路
方法一：动态规划算法-参考62题
1,  找寻 f(m, n) 和 f(m-1, n)、f(m, n-1)、f(m, n)，之间的关系
2,  画图就可以发现 f(m, n) = f(m-1, n) + f(m, n-1),知道了这个关系，剩下的就只是代码了
3,  如果(m,n)处设置障碍物，f(m,n)=0 即可
4,  动态规划法优化，减少空间，只需要dp[m]大小的数组即可

### 代码

```c


//方法一：动态规划算法-参考62题
//1,找寻 f(m, n) 和 f(m-1, n)、f(m, n-1)、f(m, n)，之间的关系
//2,画图就可以发现 f(m, n) = f(m-1, n) + f(m, n-1),知道了这个关系，剩下的就只是代码了
//3,如果(m,n)处设置障碍物，f(m,n)=0 即可
//4,动态规划法优化，减少空间，只需要dp[m]大小的数组即可

int uniquePathsWithObstacles(int** obstacleGrid, int obstacleGridSize, int* obstacleGridColSize){
    int     i       = 0;
    int     j       = 0;
    int     n       = obstacleGridSize;
    int     m       = obstacleGridColSize[0];
    long int     dp[m];

    if ((NULL == obstacleGrid) || (NULL == obstacleGridColSize) || (0 == obstacleGridSize))
    {
        return 0;
    }

    //1,动态规划求出最终解
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            if (obstacleGrid[i][j] == 1)
            {
                dp[j] = 0;
            }
            else
            {
                if ((i == 0) && (j == 0))
                {
                    dp[j] = 1;
                }
                else if (i == 0)
                {
                    dp[j] = dp[j - 1];
                }
                else if (j == 0)
                {
                    dp[j] = dp[j];
                }
                else
                {
                    dp[j] = dp[j - 1] + dp[j];
                }
            }
        }
    }

    //3,返回 dp[m-1]
    return dp[m - 1];
}
```