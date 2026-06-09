![image.png](https://pic.leetcode-cn.com/5d831843711f76eb1c97a3b4ba2df788165ab1ef1549ef25b72fae54909d48cd-image.png)
遍历grid，问每一个1，上下左右是不是0，是的话边长+1
```python []
class Solution:
    def islandPerimeter(self, grid: List[List[int]]) -> int:
        m, n = len(grid), len(grid[0])
        peri = 0
        for i in range(m):
            for j in range(n):
                if grid[i][j]:  # 如果这个地方是1的话
                    if not i or not grid[i-1][j]:  # 问它上边是不是0
                        peri += 1
                    if i == m-1 or not grid[i+1][j]:  # 问它下边是不是0
                        peri += 1
                    if not j or not grid[i][j-1]:  # 问它左边是不是0
                        peri += 1
                    if j == n-1 or not grid[i][j+1]:  # 问它右边是不是0
                        peri += 1
        return res
```

