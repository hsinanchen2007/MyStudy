### 解题思路
此题与 [200.岛屿的数量](https://leetcode-cn.com/problems/number-of-islands/) 类似。不同之处在于做`DFS`的时候要同时记录该岛屿的面积，每遍历完一个岛屿，与当前的最大面积作比较。

关于在`Python`函数内部改变外部的变量的方法,有以下几种：
1. 用 `self` 变量
2. 可以用list， dictionary 等 iterable
3. 在函数内部声明 `nonlocal` 的变量

### 代码

```python
class Solution:
    def maxAreaOfIsland(self, grid: List[List[int]]) -> int:
        if not grid: return 0
        m, n = len(grid), len(grid[0])
        self.res = 0
        def dfs(i, j):
            if 0 <= i < m and 0 <= j < n and grid[i][j] == 1: 
                self.area +=1
                grid[i][j] = 0
                for x, y in [(i-1, j), (i+1, j), (i, j-1), (i, j+1)]:
                    dfs(x, y)
        for i in range(m):
            for j in range(n):
                if grid[i][j] == 1:
                    self.area = 0
                    dfs(i, j)
                    self.res = max(self.area, self.res)
        return self.res
```