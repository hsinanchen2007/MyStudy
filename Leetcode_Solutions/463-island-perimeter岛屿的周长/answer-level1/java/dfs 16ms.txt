
class Solution {
    
    private boolean[][] visited;
    private int R;
    private int C;
    private int[] dr = {0, 1, 0, -1};
    private int[] dc = {1, 0, -1, 0};
    
    public int islandPerimeter(int[][] grid) {
        
        R = grid.length;
        if(R == 0) return 0;
        C = grid[0].length;
        visited = new boolean[R][C];
        int cnt = 0;
        for(int r = 0; r < R; r ++){
            for(int c = 0; c < C; c ++){
                if(!visited[r][c] && grid[r][c] == 1)
                    cnt += dfs(grid, r, c);
            }
        }
        
        return cnt;
    }
    
    private int dfs(int[][] grid, int r, int c){
        //越界,边为1
        if(r < 0 || r >= R || c < 0 || c >= C) return 1;
        //访问过
        if(visited[r][c]) return 0;
        //是湖，边为1
        if(grid[r][c] == 0) return 1;
        
        visited[r][c] = true;
        int cnt = 0;
        for(int d = 0; d < 4; d ++){
            int nextr = r + dr[d];
            int nextc = c + dc[d];
            cnt += dfs(grid, nextr, nextc);
        }
        return cnt;
    }
    
}