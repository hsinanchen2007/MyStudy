## 思路

看完题目就应该想到是一个动态规划题目。 我们使用dp[i][j] 表示走到grid[i][j] 我们最多能拿到多少价值的礼物。

转移方程也很简单`dp[i][j] = grid[i - 1][j - 1] + max(dp[i - 1][j], dp[i][j - 1])`，最终返回dp数组的右下角元素即可。


这道题非常常规，当然看到这里，聪明的你可能发现“dp[i][j]只和上方和左方的元素有关”，我们似乎可以讲空间复杂度优化到一维。这个留给大家来解答吧～～～



## 代码


```python
class Solution:
    def maxValue(self, grid: List[List[int]]) -> int:
        m, n = len(grid), len(grid[0])
        dp = [[0 for j in range(n + 1)]  for i in range(m + 1)]
        for i in range(1, m + 1):
            for j in range(1, n + 1):
                dp[i][j] = grid[i - 1][j - 1] + max(dp[i - 1][j], dp[i][j - 1])
        return dp[-1][-1]

```



**复杂度分析**
- 时间复杂度：$O(M * N)$
- 空间复杂度：$O(M * N)$

欢迎关注我的公众号《脑洞前端》获取更多更新鲜的LeetCode题解

![](https://pic.leetcode-cn.com/89ef69abbf02a2957838499a96ce3fbb26830aae52e3ab90392e328c2670cddc-file_1581478989502)
