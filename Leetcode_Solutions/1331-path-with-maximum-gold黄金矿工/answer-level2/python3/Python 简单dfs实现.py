![image.png](https://pic.leetcode-cn.com/469e39f7f34506a895643e930befef3ce92353569c34e66accdef10a16251e9d-image.png)


```
'''
dfs 搜索即可
'''

from typing import List
class Solution:

    def solve(self, i, j, grid: List[List[int]]) -> int:
        m, n = len(grid), len(grid[0])
        if i < 0 or i >= m or j < 0 or j >= n:
            return 0

        if grid[i][j] == 0:
            return 0

        orig_val = grid[i][j]

        grid[i][j] = 0
        ans = -0x7fffffff
        for ii, jj in [(i+1, j), (i-1, j), (i, j-1), (i, j+1)]:
            ans = max(ans, orig_val + self.solve(ii, jj, grid))

        grid[i][j] = orig_val
        return ans


    def getMaximumGold(self, grid: List[List[int]]) -> int:
        ans = 0
        for i in range(len(grid)):
            for j in range(len(grid[0])):
                if grid[i][j]:
                    ans = max(ans, self.solve(i, j, grid))
        return ans
```
