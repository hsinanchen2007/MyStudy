   def numIslands(self, grid: List[List[str]]) -> int:
        if not grid:
            return 0

        row, col = len(grid), len(grid[0])
        queue_list = []
        count = 0
        for i in range(row):
            for j in range(col):
                if grid[i][j] == '0':
                    continue
                if grid[i][j] == '1':
                    queue_list.append([i, j])
                while queue_list:
                    x, y = queue_list.pop(0)
                    grid[x][y] = '0'
                    l, r, u, d = y - 1, y + 1, x - 1, x + 1
                    if l >= 0 and grid[x][l] == '1':
                        grid[x][l] = '0'
                        queue_list.append([x, l])
                    if r < col and grid[x][r] == '1':
                        grid[x][r] = '0'
                        queue_list.append([x, r])
                    if u >= 0 and grid[u][y] == '1':
                        grid[u][y] = '0'
                        queue_list.append([u, y])
                    if d < row and grid[d][y] == '1':
                        grid[d][y] = '0'
                        queue_list.append([d, y])
                count += 1
        return count