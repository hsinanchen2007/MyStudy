![image.png](https://pic.leetcode-cn.com/b33e1e4726b82737468f4071887fde1aca0796332214ebaebd17b68473b96f4d-image.png)


```

from typing import List
class Solution:

    def dfs(self, i, j, grid, m, n, visited) -> bool:
        if i < 0 or i >= m or j < 0 or j >= n:
            return False

        if (i, j) in visited or grid[i][j] == 1:
            return True

        visited.add((i, j))
        ans = True
        for ii, jj in [[i+1, j], [i-1, j], [i, j+1], [i, j-1]]:
            if not self.dfs(ii, jj, grid, m, n, visited):
                ans = False
        return ans

    def closedIsland(self, grid: List[List[int]]) -> int:
        m, n = len(grid), len(grid[0])

        visited = set()
        ans = 0
        for i in range(m):
            for j in range(n):
                if grid[i][j] == 0 and (i, j) not in visited and self.dfs(i, j, grid, m, n, visited):
                    ans += 1
        return ans

```



