### 解题思路
很常规的思路，首先将腐烂的橘子坐标保存，随后计数正常橘子，最后进行BFS搜索检测，如果一次更新没有任何变化，则表明橘子无法全部腐烂。

### 代码

```python3
class Solution:
    def orangesRotting(self, grid: List[List[int]]) -> int:
        vol, count, time = [], 0, 0
        cal1, cal2 = len(grid), len(grid[0])
        for i in range(cal1):
            for j in range(cal2):
                if grid[i][j] == 2:
                    vol.append((i, j))
        for i in range(cal1):
            for j in range(cal2):
                if grid[i][j] == 1:
                    count += 1
        while count > 0:
            time += 1
            tempGrid = []
            flag = 0
            for i, j in vol:
                temp = [(i - 1, j), (i + 1, j), (i, j - 1), (i, j + 1)]
                for x, y in temp:
                    if 0 <= x < cal1 and 0 <= y < cal2 and grid[x][y] == 1:
                        count, grid[x][y], flag = count - 1, 2, 1
                        tempGrid.append((x, y))
            if flag == 0 and count > 0:
                return -1
            for i in tempGrid:
                vol.append(i)
        return time
```