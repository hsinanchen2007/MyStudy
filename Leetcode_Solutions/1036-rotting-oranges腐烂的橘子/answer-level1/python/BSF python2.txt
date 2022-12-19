### 解题思路
此处撰写解题思路

### 代码

```python
       row = len(grid)
        col = len(grid[0])
        rottens = [(i, j) for i in range(row) for j in range(col) if grid[i][j] == 2]
        freshes = [(i, j) for i in range(row) for j in range(col) if grid[i][j] == 1]
        time = 0
        new_rottens = rottens

        while freshes:
            if not new_rottens:
                return -1
            new_rottens = []
            for i, j in rottens:
                for new_i, new_j in [(0, 1), (0, -1), (1, 0), (-1, 0)]:
                    local = (i + new_i, j + new_j)
                    if local in freshes:
                        new_rottens.append(local)
                        freshes.remove(local)
            rottens += new_rottens
            time += 1

        return time
```