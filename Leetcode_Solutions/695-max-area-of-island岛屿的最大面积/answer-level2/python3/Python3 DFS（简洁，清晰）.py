### 解题思路
![截屏2020-03-15下午2.57.22.png](https://pic.leetcode-cn.com/c60e01ed08b1af914970836d82c5085a9e4648b1383bd9432f8135806abdf1e5-%E6%88%AA%E5%B1%8F2020-03-15%E4%B8%8B%E5%8D%882.57.22.png)


### 代码

```python []
class Solution:
    def maxAreaOfIsland(self, grid: List[List[int]]) -> int:
        m, n = len(grid), len(grid[0])
        def dfs(gird, i, j):
            if 0<=i<m and  0<=j<n and grid[i][j]:
                grid[i][j] = 0
                return 1 + dfs(grid, i+1,j) + dfs(grid, i-1, j) + dfs(grid, i, j+1) + dfs(grid, i, j-1)
            return 0
        result = 0
        for x in range(m):
            for y in range(n):
                result = max(result, dfs(grid, x, y))
        return result
```