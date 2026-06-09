### 解题思路
这一题比较简单，DP 规则和顺序都已知。 和习题[面试题47. 礼物的最大价值](https://leetcode-cn.com/problems/li-wu-de-zui-da-jie-zhi-lcof/) 很像, 不过一个是求最大路径，一个是求最小路径。

习题[面试题47. 礼物的最大价值](https://leetcode-cn.com/problems/li-wu-de-zui-da-jie-zhi-lcof/)  初始化的写法更加巧妙。


使用一个 DP 数组来进行控制。
写代码不小心有一个小 BUG
DP[0][j] = DP[0][j-1] + grid[0][j]


### 代码

```python3
class Solution:
    def minPathSum(self, grid: List[List[int]]) -> int:
        m = len(grid)
        if m == 0:
            return 0
        else:
            n = len(grid[0])
        DP = [[0]*n for _ in range(m)]
        DP[0][0] = grid[0][0]
        for j in range(1,n):
          #  DP[0][j] = DP[0][j-1] + grid[0][j-1] BUG
          DP[0][j] = DP[0][j-1] + grid[0][j]
        for i in range(1,m):
            # DP[i][0] = DP[i-1][0] + grid[i-1][0] BUG
            DP[i][0] = DP[i-1][0] + grid[i][0]
        for i in range(1,m):
            for j in range(1,n):
                DP[i][j] = min(DP[i][j-1], DP[i-1][j]) + grid[i][j]
        return DP[m-1][n-1]
```

### 另一初始化的写法更巧妙。
``` python3
        m, n = len(grid), len(grid[0])  ##已知是矩形，而不仅仅是二维数组
        DP = [[0]*n for _ in range(m)]
        for i in range(m):
            for j in range(n):
                if i == 0 and j == 0:
                    DP[i][j] = grid[0][0]
                else:
                    if j>=1:
                        DP[i][j] = max(DP[i][j-1]+grid[i][j], DP[i][j])
                    if i>=1:
                        DP[i][j] = max(DP[i-1][j]+grid[i][j], DP[i][j])
        return DP[m-1][n-1]
```