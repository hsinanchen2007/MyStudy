## 思路

和[200. 岛屿数](https://github.com/azl397985856/leetcode/blob/master/problems/200.number-of-islands.md) 思路一样。

![image.png](https://pic.leetcode-cn.com/e611eb47fa6c2874bb10c37cd45a23143a450e3268022152ee7a519bdff0d907-image.png)

这道题目仍然可以采用原位修改的方式避免记录visited的开销。我们的做法是将`grid[i][j] = 0`，需要注意的是，我们无需重新将`grid[i][j] = 1`,因为题目没有这个要求。另外如果你这么做的话，也会产生bug，
比如：


1**1**1
111

上面加粗的1，如果在遍历了上下左右邻居之后，将0，重新变成1。那么就会被重复计算。如下，粗体上方的1就会被计算多次

111
10**1**

## 代码


```python
class Solution:
    def maxAreaOfIsland(self, grid: List[List[int]]) -> int:
        m = len(grid)
        if m == 0: return 0
        n = len(grid[0])
        ans = 0
        def dfs(i, j):
            if i < 0 or i >= m or j < 0 or j >= n: return 0
            if grid[i][j] == 0: return 0
            grid[i][j] = 0
            top = dfs(i + 1, j)
            bottom = dfs(i - 1, j)
            left = dfs(i, j - 1)
            right = dfs(i, j + 1)
            return 1 + sum([top, bottom, left, right])
        for i in range(m):
            for j in range(n):
                ans = max(ans, dfs(i, j))
        return ans
```

**复杂度分析**
- 时间复杂度：$O(m * n)$
- 空间复杂度：$O(m * n)$

欢迎关注我的公众号《脑洞前端》获取更多更新鲜的LeetCode题解

![](https://pic.leetcode-cn.com/89ef69abbf02a2957838499a96ce3fbb26830aae52e3ab90392e328c2670cddc-file_1581478989502)
