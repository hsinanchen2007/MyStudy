### 解题思路
回溯问题 == 多叉树的深度遍历 + 剪枝

![image.png](https://pic.leetcode-cn.com/a929872d568f73160d618779859a9c8fd18f4997354ce53bbbf9f645573be052-image.png)

### 代码

```python3
class Solution:
    def uniquePathsIII(self, grid: List[List[int]]) -> int:
        row = len(grid)
        col = len(grid[0])
        start = tuple()
        end = tuple()
        hider = []
        directions = [(-1, 0), (0, 1), (1, 0), (0, -1)]
        for i in range(row):
            for j in range(col):
                if grid[i][j] == 1:
                    start = (i,j)
                if grid[i][j] == 2:
                    end = (i, j)
                if grid[i][j] == -1:
                    hider.append((i, j))
        print(start, end)
        res = []
        path = [start]

        def backtrack(start, path):
            if len(path) == (row * col) - len(hider) and path[-1] == end: # 终止条件
                res.append(path[:])
                return 

            for dx, dy in directions:
                cur_x, cur_y = start
                x = cur_x + dx
                y = cur_y + dy
                if x in range(0, row) and y in range(0, col) and grid[x][y] != -1 and (x, y) not in path:# 剪枝
                    backtrack((x, y), path + [(x, y)])
        
        backtrack(start, path)

        return len(res)

            
```