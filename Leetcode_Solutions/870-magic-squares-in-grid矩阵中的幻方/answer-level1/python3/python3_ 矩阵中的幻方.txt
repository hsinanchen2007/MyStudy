```python
def numMagicSquaresInside(grid):
    def help(grid, i, j):
        # 确定数字为1~9
        col1, col2, col3 = grid[i][j:j+3], grid[i+1][j:j+3], grid[i+2][j:j+3]
        if set(col1).union(set(col2)).union(set(col3)) != set(range(1,10)):
            return False
        # 每行比较
        if not all([sum(grid[i][j:j+3]) == 15,
              sum(grid[i+1][j:j+3]) == 15,
              sum(grid[i+2][j:j+3]) == 15]):
            return False
        # 每列比较
        for k in range(3):
            if not (grid[i][j + k] + grid[i+1][j + k] + grid[i+2][j+k] == 15):
                return False
        # 斜比较
        if not (grid[i][j] + grid[i+1][j+1] + grid[i+2][j+2] == 15):
            return False
        if not (grid[i][j+2] + grid[i+1][j+1] + grid[i+2][j] == 15):
            return False
        return True
    
    m, n = len(grid), len(grid[0])
    r = 0
    for i in range(m - 2):
        for j in range(n - 2):
            if help(grid, i, j):
                r += 1
    return r

grid = [[4,3,8,4],[9,5,1,9],[2,7,6,2]]
print(numMagicSquaresInside(grid))
```