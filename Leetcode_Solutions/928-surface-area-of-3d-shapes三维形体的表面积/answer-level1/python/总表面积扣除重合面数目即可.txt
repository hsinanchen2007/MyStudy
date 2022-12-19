### 解题思路
不考虑相邻网格之间的重合，每个网格贡献的表面积为
$$
s(i) = \begin{cases}
4\times i+2, &\quad i \gt 0 \\
0,&\quad i = 0
\end{cases}
$$
$i$为网格上的正方体个数。遍历网盘，得到表面积的总贡献为
$$
\begin{aligned}
total & = \sum_{i=0}^{rows}\sum_{j=0}^{cols} s(grid[i][j])
\end{aligned}
$$
接下来按行和列方向分别计算重合面的数目，总和记为$m$。则最终形体的表面积为
$$
ans = total - m
$$

### 代码

```python
class Solution(object):
    def surfaceArea(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        total = 0
        n, m = len(grid), len(grid[0])
        for i in range(n):
            for j in range(m):
                if grid[i][j]:
                    total += 4 * grid[i][j] + 2
        conceal = 0
        for i in range(n):
            for j in range(m-1):
                conceal += min(grid[i][j], grid[i][j+1])
        for i in range(n-1):
            for j in range(m):
                conceal += min(grid[i][j], grid[i+1][j])
        # print conceal
        ans = total - 2 * conceal
        return ans
```