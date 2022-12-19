## 思路


思路可以参考我的这篇题解[200.number-of-islands](https://github.com/azl397985856/leetcode/blob/master/problems/200.number-of-islands.md)


和200题的思路完全一致，只不过200是求小岛个数，这个是求小岛最大面积，这也就是多一个变量记录一下的事情。


![](https://pic.leetcode-cn.com/911f2cf8b839350d665acb83ec0fbc443c780e4d6b6c559b535e2e9694dbf74d.jpg)

## 代码


```
class Solution:
    def maxAreaOfIsland(self, grid: List[List[int]]) -> int:
        self.max_area = 0
        self.cnt = 0
        m = len(grid)
        if m == 0: return
        n = len(grid[0])

        def dfs(i, j):
            if i < 0 or i >= m or j < 0 or j >= n: return
            if grid[i][j] == 1:
                self.cnt += 1
                grid[i][j] = 0
                dfs(i + 1, j)
                dfs(i - 1, j)
                dfs(i, j + 1)
                dfs(i, j - 1)

        for i in range(m):
            for j in range(n):
                self.cnt = 0
                dfs(i, j)
                self.max_area = max(self.max_area, self.cnt)
        return self.max_area


```

*复杂度分析**
- 时间复杂度：$O(M^2*N^2)$
- 空间复杂度：$O(M*N)$

欢迎关注我的公众号《脑洞前端》获取更多更新鲜的LeetCode题解

![](https://pic.leetcode-cn.com/89ef69abbf02a2957838499a96ce3fbb26830aae52e3ab90392e328c2670cddc-file_1581478989502)
