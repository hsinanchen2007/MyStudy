# 思路

## 最优值定义和转移方程

$dp[i][j]$ 为从左上角走到 $(i, j)$ 点的**路径条数**, 转移方程:  
$$dp[i][j] = dp[i][j-1] + dp[i-1][j]$$
注意： 当 $(i, j)$ 为**障碍**时, $dp[i][j] = 0$   
索引从 0 开始, 最终结果为 $dp[n-1][m-1]$
## 边界值

首先对于**第零行**, 从左至右, 遇到一个障碍就停下, 左面的所有元素, $dp[0][i] = 1$  

其次对于**第零列**, 从上至下, 遇到一个障碍就停下, 上面的所有元素, $dp[0][j] = 1$

## 内存优化

观察转移方程, 可见 $dp[i][j]$ 只使用了其**上方** ($dp[i-1][j]$) 和 **左方** ($dp[i][j-1]$) 的元素，求解过程一定是**从上到下, 从左到右**, 所以二维数组 ```dp[N][M]``` 可以这样优化：  
- 滚动数组
  即 ```dp[2][M]```, 保存了 **当前行** 和 **上一行** 的 $dp$ 值, 求解过程中 "当前行" 和 "上一行" 彼此交换, 使用游标 ```int p``` 指向当前行, ```p = 0``` 或 ```p = 1```, 最终结果为 ```dp[p][m-1]```

- 直接优化为**一维数组**
  即 ```dp[M]```, 在从左到右求解的过程中, 还未计算过的当前值 $dp[i]$ 即为 "上方" 的值, 已经求解完毕的 $dp[i-1]$ 即为 "左方" 的值；不断从左到右, 在 ```dp[M]```上迭代 n-1 次, 最终结果为 ```dp[m-1]```

注意事项:

- 若优化了内存, 则 **第零列** 的边界值**无法直接初始化**, 实现细节见源码
- ```int``` 会溢出, 使用 ```long long dp[]``` 

# 滚动数组
```cpp
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        const int N = 105;
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();

        if (!n || !m || obstacleGrid[0][0] == 1 || obstacleGrid[n-1][m-1] == 1)
            return 0;

        long long dp[2][N];
        memset(dp, 0, sizeof(dp));

        int p = 0;    // 指向行的游标
        // 初始化
        for (int j = 0; j < m && obstacleGrid[0][j] != 1; j ++)
            dp[p][j] = 1;
        
        int maxRow = 0;  // dp[row][0] == 1 的最大行数
        for (int i = 1; i < n && obstacleGrid[i][0] != 1; i ++)
            maxRow = i;

        for (int i = 1; i < n; i ++){
            p = 1 - p;      // p 指向当前行
            dp[p][0] = i <= maxRow ? 1:0;   // 初始化当前行第一列的值

            for (int j = 1; j < m; j ++){
                if (obstacleGrid[i][j] == 1)    // 障碍
                    dp[p][j] = 0;
                else   // 不是障碍
                    dp[p][j] = dp[p][j-1] + dp[1-p][j];
            }
        }
        return (int)dp[p][m-1];
    }
};
```

# 一维数组
```cpp
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        const int N = 105;
        int n = obstacleGrid.size();        // 行数
        int m = obstacleGrid[0].size();     // 列数

        if (!n || !m || obstacleGrid[0][0] == 1 || obstacleGrid[n-1][m-1] == 1)
            return 0;

        long long dp[N];
        memset(dp, 0, sizeof(dp));

        // 初始化
        for (int j = 0; j < m && obstacleGrid[0][j] != 1; j ++)
            dp[j] = 1;

        int maxRow = 0;     // 第0列, 直到 maxRow 行为止 dp[i][0] 都为 1 (压缩的第一列的 dp[i][j])
        for (int i = 1; i < n && obstacleGrid[i][0] != 1; i ++)
            maxRow = i;

        for (int i = 1; i < n; i ++){
            dp[0] = i <= maxRow ? 1:0;      // 初始化当前行第一列元素
            for (int j = 1; j < m; j ++){
                if (obstacleGrid[i][j] == 1)    // 是障碍
                    dp[j] = 0;
                else        // 不是障碍
                    dp[j] += dp[j-1];
            }
        }
        return (int)dp[m-1];
    }
};
```
