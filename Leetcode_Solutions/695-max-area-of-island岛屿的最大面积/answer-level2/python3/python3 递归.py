### 解题思路
找到陆地（值为1）,并由此找到并计算整个岛屿的面积(深度有限，递归)，在计算的过程中，将计算过的部分置为0，避免重复计算
储存所有陆地，获得最大值

### 代码

```python3
class Solution:
    def maxAreaOfIsland(self, grid: List[List[int]]) -> int:
        length = len(grid)
        width = len(grid[0])
        def search(x, y,count):
            grid[x][y] = 0
            if x > 0 and grid[x - 1][y] == 1:
                count[0] += 1
                search(x - 1, y,count)
            if y > 0 and grid[x][y - 1] == 1:
                count[0] += 1
                search(x, y - 1,count)
            if x < length - 1 and grid[x + 1][y] == 1:
                count[0] += 1
                search(x + 1, y,count)
            if y < width - 1 and grid[x][y + 1] == 1:
                count[0] += 1
                search(x, y + 1,count)
        max_area = []
        for i in range(length):
            for j in range(width):
                if grid[i][j] == 1:
                    count = [1]
                    search(i, j,count)
                    max_area.append(count[0])
        if len(max_area)==0:
            return 0
        return max(max_area)
```