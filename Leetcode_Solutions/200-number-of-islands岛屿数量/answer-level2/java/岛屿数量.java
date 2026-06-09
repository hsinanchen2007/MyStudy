DFS 遍历

```
    private boolean[][] isUsed;
    private int row;
    private int col;
    
    public int numIslands(char[][] grid) {
        row = grid.length;
        if(row == 0) return 0;
        col = grid[0].length;
        isUsed = new boolean[row][col];
        
        int ans = 0;
        for(int i=0; i<row; i++)
            for(int j=0; j<col; j++){
                if(grid[i][j] == '1' && !isUsed[i][j]){
                    ans ++;
                    solve(grid, i, j);
                }
            }
        
        return ans;
    }
    
    private void solve(char[][] arr, int x, int y){
        if(arr[x][y] == '0' || isUsed[x][y]) return;
        isUsed[x][y] = true;
        
        int[] dx ={1, 0, -1, 0}, dy = {0, 1, 0, -1};
        for(int i=0; i<4; i++){
            int mx = x + dx[i];
            int my = y + dy[i];
            if(mx >=0 && mx < row && my >=0 && my<col){
                solve(arr, mx, my);
            }
        }
        
    }
```
