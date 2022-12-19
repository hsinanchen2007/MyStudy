- 使用动态规划
![Snipaste_2019-09-09_11-48-12.png](https://pic.leetcode-cn.com/6e080653b755cd7d99d703d7416cd2e9b1a649e7117b3801ceb4e78bb4e3c1f1-Snipaste_2019-09-09_11-48-12.png)

- 两遍扫描

- 第一遍从左上角开始扫描

  - 判断是否是陆地，如果是陆地，距离更新为0
  - 如果是海洋，判断上面和左面是不是陆地，更新到陆地的最小距离

- 第二遍从右下角扫描

  - 如果是海洋，判断右面和下面是不是陆地，更新到陆地的最小距离
  - 更新海洋到陆地的最大距离


```python
class Solution:
    def maxDistance(self, grid: List[List[int]]) -> int:
        
        
        inf = float('inf')
        row, col = len(grid), len(grid[0])
        distance = [[inf for _ in range(col)] for _ in range(row)]

        min_island = -1

        # 坐标验证
        def available(m, n):
            return 0 <= m < row and 0 <= n < col

        for i in range(row):
            for j in range(col):
                if grid[i][j] == 1:
                    distance[i][j] = 0
                else:
                    top, left = inf, inf
                    if available(i - 1, j):
                        if distance[i - 1][j] != inf and distance[i - 1][j] >= 0:
                            top = distance[i - 1][j] + 1
                    if available(i, j - 1):
                        if distance[i][j - 1] != inf and distance[i ][j - 1] >= 0:
                            left = distance[i][j - 1] + 1
                    distance[i][j] = min(top, left)
        for i in range(row - 1, -1, -1):
            for j in range(col - 1, -1, -1):
                if grid[i][j] == 0:
                    right, bottom = inf, inf

                    if available(i, j + 1):
                        if distance[i][j + 1] != inf and distance[i][j + 1] >= 0:
                            right = distance[i][j + 1] + 1
                    if available(i + 1, j):
                        if distance[i + 1][j] != inf and distance[i + 1][j] >= 0:
                            bottom = distance[i + 1][j] + 1

                    distance[i][j] = min(distance[i][j], right, bottom)

                    if distance[i][j] != inf:
                        min_island = max(min_island, distance[i][j])
        return min_island if min_island != inf else -1
```


