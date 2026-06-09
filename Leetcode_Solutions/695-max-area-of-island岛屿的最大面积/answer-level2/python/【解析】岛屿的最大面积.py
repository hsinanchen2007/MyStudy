### 解题思路
又是一道深度优先搜索题，最开始没看懂题意，其实要求的就是连成片的最多1的数量。思路是：遍历每一个格子，如果它是1，就往它的上下左右遍历，每遍历一个格子为了防止重复遍历就把它置为0。

### 代码

```python3
class Solution:
    def dfs(self, grid, cur_i, cur_j):
        print(str(cur_i) + "\t" + str(cur_j))
        if cur_i < 0 or cur_j < 0 or cur_i == len(grid) or cur_j == len(grid[0]) or grid[cur_i][cur_j] != 1:
            # print("returned 0")
            return 0
        grid[cur_i][cur_j] = 0
        ans = 1
        for di, dj in [[0, 1], [0, -1], [1, 0], [-1, 0]]:
            next_i, next_j = cur_i + di, cur_j + dj
            ans += self.dfs(grid, next_i, next_j)
        # print("answer is: " + str(ans))
        return ans

    def maxAreaOfIsland(self, grid: List[List[int]]) -> int:
        ans = 0
        for i, m in enumerate(grid):
            for j, n in enumerate(m):
                tmp = self.dfs(grid, i, j)
                if tmp >= ans:
                    ans = tmp
        return ans
```