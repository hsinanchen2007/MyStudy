头疼。
```
class Solution {
    boolean dfs(int[][] grid, int dir, int i, int j, int[][] visited){
        if(i < 0 || i >= grid.length || j < 0 || j >= grid[0].length || visited[i][j] == 1){
            return false;
        }
        // 0123 上下左右
        if(dir == 0){
            if(grid[i][j] != 3 && grid[i][j] != 4 && grid[i][j] != 2){
                return false;
            }
        }
        if(dir == 1){
            if(grid[i][j] != 5 && grid[i][j] != 2 && grid[i][j] != 6){
                return false;
            }
        }
        if(dir == 2){
            if(grid[i][j] != 4 && grid[i][j] != 6 && grid[i][j] != 1){
                return false;
            }
        }
        if(dir == 3){
            if(grid[i][j] != 3 && grid[i][j] != 5 && grid[i][j] != 1){
                return false;
            }
        }
        if(i == grid.length - 1 && j == grid[0].length - 1){
            return true;
        }
        visited[i][j] = 1;
        boolean res = false;
        switch(grid[i][j]){
            case 1:
                res = dfs(grid, 2, i, j - 1, visited) || dfs(grid, 3, i, j + 1, visited);
                break;
            case 2:
                res = dfs(grid, 0, i - 1, j, visited) || dfs(grid, 1, i + 1, j, visited);
                break;
            case 3:
                res = dfs(grid, 2, i, j - 1, visited) || dfs(grid, 1, i + 1, j, visited);
                break;
            case 4:
                res = dfs(grid, 3, i, j + 1, visited) || dfs(grid, 1, i + 1, j, visited);
                break;
            case 5:
                res = dfs(grid, 2, i, j - 1, visited) || dfs(grid, 0, i - 1, j, visited);
                break;
            case 6:
                res = dfs(grid, 0, i - 1, j, visited) || dfs(grid, 3, i, j + 1, visited);
                break;
        }
        return res;
        
    }
    public boolean hasValidPath(int[][] grid) {
        if(grid.length == 1 && grid[0].length == 1){
            return true;
        }
        boolean res = false;
        int[][] visited = new int[grid.length][grid[0].length];
        visited[0][0] = 1;
        switch(grid[0][0]){
            case 4:
                res = dfs(grid, 1, 1, 0, visited);
                break;
            case 1:
                res = dfs(grid, 3, 0, 1, visited);
                break;
            case 2:
                res = dfs(grid, 1, 1, 0, visited);
                break;
            case 3:
                res = dfs(grid, 1, 1, 0, visited);
                break;
            case 6:
                res = dfs(grid, 3, 0, 1, visited);
                break;
        }
        return res;
    }
}
```
