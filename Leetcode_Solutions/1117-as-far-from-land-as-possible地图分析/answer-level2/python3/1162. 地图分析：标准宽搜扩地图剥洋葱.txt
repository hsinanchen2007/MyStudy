宽搜一遍过，一层一层拓展地图，相当于把海洋一层一层缩小，直到访问了所有的点就结束。
```python []
class Solution:
    def maxDistance(self, grid: List[List[int]]) -> int:
        n = len(grid)
        que = [(i, j) for j in range(n) for i in range(n) if grid[i][j]]
        if not 0 < len(que) < n * n:
            return -1
        ans = -1
        while que:
            que = [
                grid[x].__setitem__(y, 1) or (x, y)
                for i, j in que
                for x, y in ((i + 1, j), (i - 1, j), (i, j + 1), (i, j - 1))
                if 0 <= x < n and 0 <= y < n and (x, y) and not grid[x][y]
            ]
            ans += 1
        return ans
```

```python []
class Solution:
    def maxDistance(self, grid: List[List[int]]) -> int:
        n = len(grid)
        que = [(i, j) for j in range(n) for i in range(n) if grid[i][j]]
        if not 0 < len(que) < n * n:
            return -1
        ans = -1
        while que:
            tmp = []
            for i, j in que:
                for x, y in ((i + 1, j), (i - 1, j), (i, j + 1), (i, j - 1)):
                    if 0 <= x < n and 0 <= y < n and (x, y) and not grid[x][y]:
                        tmp.append((x, y))
                        grid[x][y] = 1
            que = tmp
            ans += 1
        return ans
```

提交人数较少，784ms仅供参考。

![image.png](https://pic.leetcode-cn.com/2a172eb1828af46cf9260ddac0ae066163f57a3007d0f5f16dd4ae380cb46c4e-image.png)

