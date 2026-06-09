
![image.png](https://pic.leetcode-cn.com/b21350eb05f6281b4c240114d01c1cd8074c9906c816238bdf2f5b6f0dfbe83c-image.png)

```
class Solution:
    def maxDistance(self, grid) -> int:
        '''
        思路:
        1.BFS,对每个海洋顶点BFS,当遇到最近的陆地则退出,遍历所有的海洋,最坏O(len(grid)^2*len(grid[0])^2)
        2.对每个陆地顶点BFS,"填海",当最后被填的海离所有陆地最远,时间复杂度O(len(grid)*len(grid[0]))
        '''
        max_dist = -1
        visited = [[False] * len(grid[0]) for _ in range(len(grid))]
        queue = []
        for i in range(len(grid[0])):
            for j in range(len(grid[1])):
                if grid[i][j]:
                    for neighbor in [(i - 1, j), (i + 1, j), (i, j - 1), (i, j + 1)]:
                        if 0 <= neighbor[0] < len(grid[0]) and 0 <= neighbor[1] < len(grid) and \
                                (not visited[neighbor[0]][neighbor[1]]) and grid[neighbor[0]][neighbor[1]] == 0:
                            visited[neighbor[0]][neighbor[1]] = True
                            queue.append((neighbor[0], neighbor[1], 1))
        while queue:
            i, j, dist = queue.pop(0)
            max_dist = dist
            for neighbor in [(i - 1, j), (i + 1, j), (i, j - 1), (i, j + 1)]:
                if 0 <= neighbor[0] < len(grid[0]) and 0 <= neighbor[1] < len(grid) and \
                        (not visited[neighbor[0]][neighbor[1]]) and grid[neighbor[0]][neighbor[1]] == 0:
                    visited[neighbor[0]][neighbor[1]] = True
                    queue.append((neighbor[0], neighbor[1], dist + 1))
        return max_dist

```
