### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def orangesRotting(self, grid: List[List[int]]) -> int:
        # 从腐烂的橘子开始广搜
        # 广搜这里看一下差别，为啥有些从-1开始有些从0开始？
        queue = [(x, y, 0) for x in range(len(grid)) for y in range(len(grid[0])) if grid[x][y] == 2]
        # 没有腐烂的橘子也没有新鲜橘子返回0，没有腐烂的橘子有新鲜橘子返回-1
        signal = False
        if not queue:
            for i in range(len(grid)):
                if 1 in grid[i]:
                    signal = True
            return 0 if not signal else -1
        while queue:
            for _ in queue:
                current = queue.pop(0)
                for i, j in [[1, 0], [-1, 0], [0, 1], [0, -1]]:
                    tx = current[0] + i 
                    ty = current[1] + j
                    if not (0 <= tx < len(grid) and 0 <= ty < len(grid[0])):
                        continue
                    elif grid[tx][ty] == 1:
                        grid[tx][ty] = 2
                        queue.append((tx, ty, current[2] + 1))
        for i in range(len(grid)):
            for j in range(len(grid[0])):
                if grid[i][j] == 1:
                    return -1
        return current[2]

```