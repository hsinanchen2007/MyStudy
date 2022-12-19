```
class Solution {
    public int numIslands(char[][] grid) {
        int ans = 0;
        for (int i = 0; i < grid.length; i++) {
            for (int j = 0; j < grid[0].length; j++) {
                if (grid[i][j] == '1') {
                    ans++;
                    infect(i, j, grid);
                }
            }
        }
        return ans;
    }
    public void infect(int i, int j, char[][] grid) {
        grid[i][j] = '2';
        if (i < grid.length - 1 && grid[i+1][j] == '1') infect(i+1, j, grid);
        if (j < grid[0].length - 1 && grid[i][j+1] == '1') infect(i, j+1, grid);
        if (i > 0 && grid[i-1][j] == '1') infect(i-1, j, grid);
        if (j > 0 && grid[i][j-1] == '1') infect(i, j-1, grid);
    }
}
```
