大神的做法
```python
class Solution:
    def shiftGrid(self, grid: List[List[int]], k: int) -> List[List[int]]:
        n = len(grid)
        m = len(grid[0])
        ans = [[0] * m for i in range(n)]
        for i in range(n):
            for j in range(m):
                l=(i*m+j+k)%(n*m);
                ans[l//m][l%m]=grid[i][j];
        return ans
```
我的做法
```python
class Solution:
    def shiftGrid(self, grid: List[List[int]], k: int) -> List[List[int]]:
        n = len(grid)
        m = len(grid[0])
        c = [0 for i in range(m)]
        x = m - 1
        for i in range(k):
            c[(x - i % m)] += 1
        x = -k % m
        r = []
        for i in range(m):
            col = []
            cn = (x + i) % m
            xx = -c[cn]
            for i in range(n):
                col.append(grid[(xx+i)%n][cn])
            r.append(col)
        for i in range(n):
            for j in range(m):
                grid[i][j] = r[j][i]
        return grid
```

[我的博客](https://codeplot.top/2019/11/17/leetcode-%E5%91%A8%E8%B5%9B-163-5263-%E4%BA%8C%E7%BB%B4%E7%BD%91%E6%A0%BC%E8%BF%81%E7%A7%BB-python-%E8%A7%A3%E6%B3%95/)