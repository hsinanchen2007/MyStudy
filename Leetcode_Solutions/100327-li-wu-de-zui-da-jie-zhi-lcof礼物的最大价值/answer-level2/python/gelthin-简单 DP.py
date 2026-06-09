### 解题思路
同习题 [64. 最小路径和](https://leetcode-cn.com/problems/minimum-path-sum/)， 不过这里是求最大路径。

有向无环图
重叠子问题
最优子结构
可以使用 DP 解法，
+ 关键是如何构造 DP 状态， 最好用的 DP 状态是 DP[i][j] 表示 以 [i][j] 元素为结尾的某一个可行（部分）解
+ 还需要注意 DP 矩阵如何初始化
+ DP 矩阵的计算方向，计算顺序，这些子问题是怎么相互依赖的。

这一题比较简单，计算方向，计算顺序都非常明显。
就是 DP 最开始设置初始值需要注意一下。

### 代码

```python3
class Solution:
    def maxValue(self, grid: List[List[int]]) -> int:
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