代码如下:
class Solution {
    private ArrayList<Integer> list = new ArrayList<>();
    private int R,C;
    private int[][] dir = {{1,0},{0,1},{-1,0},{0,-1}};
    private int[][] grid ;
    private int[][] ccid;
    private int[][] table;
    public int largestIsland(int[][] grid) {
        this.grid = grid;
        this.R = grid.length;
        this.C = grid[0].length;
        table = new int[R][C];
        ccid = new int[R][C];
        int id = 1;
        for(int i = 0; i < R; i ++){
            for(int j = 0; j < C; j ++){
                if(grid[i][j] == 1 && ccid[i][j] == 0){
                    list.add(dfs(i,j,id));
                    id ++;
                }
            }
        }
        if(id == 1){
            return 1;
        }
        int cnt = 1;
        for(int i = 0; i < R && cnt < id; i ++){
            for(int j = 0; j < C && cnt < id; j ++){
                if(grid[i][j] == 1 && ccid[i][j] == cnt){
                    paint(i,j,list.get(cnt - 1),cnt);
                    cnt ++;
                }
            }
        }
        int res = 0x80000000;
        for(int i = 0; i < R; i ++){
            for(int j = 0; j < C; j ++){
                res = Math.max(table[i][j],res);
            }
        }
        return res;
    }
    private void paint(int x, int y, int color,int id){
        table[x][y] = color;
        for(int i = 0; i < dir.length; i ++) {
            int nextx = x + dir[i][0];
            int nexty = y + dir[i][1];
            if(inArea(nextx,nexty)){
                if(ccid[nextx][nexty] == id){
                    if(table[nextx][nexty] == 0) {
                        paint(nextx, nexty, color, id);
                    }
                }else{
                    if(table[nextx][nexty] == 0){
                        table[nextx][nexty] ++;
                    }
                    table[nextx][nexty] += color;
                    ccid[nextx][nexty] = id;

                }
            }
        }
    }
    private int dfs(int x, int y,int id){
        ccid[x][y] = id;
        int cnt = 1;
        for(int i = 0; i < dir.length; i ++) {
            int nextx = x + dir[i][0];
            int nexty = y + dir[i][1];
            if (inArea(nextx, nexty) && grid[nextx][nexty] == 1 && ccid[nextx][nexty] == 0) {
                cnt += dfs(nextx, nexty,id);
            }
        }
        return cnt;
    }
    private boolean inArea(int x, int y){
        return x >= 0 && x < R && y >= 0 && y < C;
    }

    public static void main(String[] args) {
        int[][] grid = {{1,1},{1,0}};
        new Solution().largestIsland(grid);
    }
}