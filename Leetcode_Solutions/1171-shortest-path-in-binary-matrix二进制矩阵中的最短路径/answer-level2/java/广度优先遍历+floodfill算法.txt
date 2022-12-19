```
class Solution {

    private int[][] dirs = {{-1,0},{-1,1},{0,1},{1,1},{1,0},{1,-1},{0,-1},{-1,-1}};
    private int line,column;

    public int shortestPathBinaryMatrix(int[][] grid) {
        line = grid.length;
        column = grid[0].length;

        boolean[][] visited = new boolean[line][column];
        int[][] dis = new int[line][column];

        if(grid[0][0] == 1) return -1;
        if(line == 1 && column == 1) return 1;

        //bfs过程
        Queue<Integer> queue = new LinkedList<>();
        queue.add(0);
        visited[0][0] = true;
        dis[0][0] = 1;
        while(!queue.isEmpty()){
            int cur = queue.remove();
            int curx = cur / column, cury = cur % column;
            for(int d=0;d<8;d++){
                int nextx = curx + dirs[d][0];
                int nexty = cury + dirs[d][1];
                if(inArea(nextx,nexty) && !visited[nextx][nexty] && grid[nextx][nexty] == 0){
                    queue.add(nextx * column + nexty);
                    visited[nextx][nexty] = true;
                    dis[nextx][nexty] = dis[curx][cury] + 1;

                    if(nextx == line - 1 && nexty == column - 1){
                        return dis[nextx][nexty];
                    }
                }
            }
        }
        return -1;
    }

    private boolean inArea(int x, int y){
        return x >= 0 && x < line && y >=0 && y < column;
    }
}
```
