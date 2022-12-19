### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        # 遍历找到1然后开启BFS，将访问过的节点置0
        count = 0
        queue = []
        if not grid:return 0
        for i in range(len(grid)):
            for j in range(len(grid[0])):
                if grid[i][j] == "1":
                    count += 1
                    queue.append((i, j))
                    while queue:
                        current = queue.pop(0)
                        grid[current[0]][current[1]] = "0"
                        for x, y in [[1, 0], [-1, 0], [0, 1], [0, -1]]:
                            tx = current[0] + x
                            ty = current[1] + y
                            if not (0 <= tx < len(grid) and 0 <= ty < len(grid[0])):
                                continue
                            elif grid[tx][ty] == "1":
                                queue.append((tx, ty))
                                grid[tx][ty] = "0"
        return count
```