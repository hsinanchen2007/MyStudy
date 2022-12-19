## 思路:

与上一题一样[62. 不同路径](https://leetcode-cn.com/problems/unique-paths/),用动态规划

`dp[i][j]`表示到`i,j`位置的总步数,因为这道题有了障碍物,所以我们有障碍物的地方到不了就设置为`0`

动态方程: `dp[i][j] = dp[i-1][j] + dp[i][j-1]`

注意,针对`dp`数组第一行,或者第一列要重新设置,考虑障碍物的情况!

当然空间还可以从二维优化到一维,参考[上一题的题解](https://leetcode-cn.com/problems/unique-paths/solution/dong-tai-gui-hua-by-powcai-2),二维更容易理解一点!

再附上一个自顶向下的动态规划! 只要 `Python`, 大家可以提供一下 `Java`版呢?

## 代码:

自底向上

```python [1]
  def uniquePathsWithObstacles(self, obstacleGrid: List[List[int]]) -> int:    
        if not obstacleGrid or not obstacleGrid[0]: return 0
        row = len(obstacleGrid)
        col = len(obstacleGrid[0])
        dp = [[0]*col for _ in range(row)]
        # 首位置
        dp[0][0] = 1 if obstacleGrid[0][0] != 1 else 0
        if dp[0][0] == 0: return 0
        # 第一行
        for j in range(1, col):
            if obstacleGrid[0][j] != 1:
                dp[0][j] = dp[0][j-1]
        # 第一列
        for i in range(1, row):
            if obstacleGrid[i][0] != 1:
                dp[i][0] = dp[i-1][0]
        for i in range(1, row):
            for j in range(1, col):
                if obstacleGrid[i][j] != 1:
                    dp[i][j] = dp[i-1][j] + dp[i][j-1]
        return dp[-1][-1]
```



```java [1]
class Solution {
    public int uniquePathsWithObstacles(int[][] obstacleGrid) {
        if (obstacleGrid == null) return 0;
        int[][] dp = new int[obstacleGrid.length][obstacleGrid[0].length];
        // 第一个数
        dp[0][0] = obstacleGrid[0][0] == 0 ? 1 : 0;
        if (dp[0][0] == 0) return 0;
        // 第一行
        for (int j = 1; j < obstacleGrid[0].length; j++) {
            if (obstacleGrid[0][j] != 1) {
                dp[0][j] = dp[0][j - 1];
            }
        }
        // 第一列
        for (int i = 1; i < obstacleGrid.length; i++) {
            if (obstacleGrid[i][0] != 1) {
                dp[i][0] = dp[i - 1][0];
            }
        }

        for (int i = 1; i < obstacleGrid.length; i++) {
            for (int j = 1; j < obstacleGrid[0].length; j++) {
                if (obstacleGrid[i][j] != 1) dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
        return dp[obstacleGrid.length - 1][obstacleGrid[0].length - 1];
    }
}
```

自顶向下

```python [2]
class Solution:
    def uniquePathsWithObstacles(self, obstacleGrid: List[List[int]]) -> int:    
        import functools
        if not obstacleGrid or not obstacleGrid[0]: return 0
        row = len(obstacleGrid)
        col = len(obstacleGrid[0])
        @functools.lru_cache(None)
        def helper(i,j):
            if i == row - 1 and j == col - 1 and obstacleGrid[i][j] != 1:
                return 1
            if i >= row or j >= col or obstacleGrid[i][j] == 1 :
                return 0
            tmp = 0
            tmp += helper(i+1, j)
            tmp += helper(i, j+1)
            return tmp
        return helper(0, 0)
```

