```
class Solution {
    private int max = 0;
    
    public int getMaximumGold(int[][] grid) {
        int row = grid.length,col = grid[0].length;
        boolean[][] vis = new boolean[row][col];
        for(int i = 0;i < row;i++){
            for(int j = 0;j < col;j++){
                if(grid[i][j] != 0)
                    dfs(grid,i,j,0,vis);
                
            }
        }
        
        return max;
    }
    
    private void dfs(int[][] grid,int x,int y,int gold,boolean[][] vis){
        if((x < 0 || x >= grid.length) || (y < 0 || y >= grid[0].length) || grid[x][y] == 0 || vis[x][y]){
            max = Math.max(max,gold);
            return;
        }
        gold += grid[x][y];
        vis[x][y] = true;
        dfs(grid,x + 1,y,gold,vis);
        dfs(grid,x - 1,y,gold,vis);
        dfs(grid,x,y + 1,gold,vis);
        dfs(grid,x,y - 1,gold,vis);
        vis[x][y] = false;
    }
}
```
