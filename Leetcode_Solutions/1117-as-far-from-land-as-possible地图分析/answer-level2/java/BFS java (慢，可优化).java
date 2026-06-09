对每个海洋块进行BFS，若第一次访问到陆地即为最近的陆地(无权图)，此时更新距离即可返回。
标记数组可以将二维坐标映射成一维坐标。:)
便于自己理解，把功能写成了函数:)

```
private int[][]dirs = {{0,1},{-1,0},{0,-1},{1,0}};
private int maxDis = -1;//记录结果
private int n;
private int[][] grid;
public int maxDistance(int[][] grid) {
    this.n = grid.length;
    this.grid = grid;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            if(grid[i][j]==0)bfs(i,j);//对每个海洋进行bfs
    return maxDis;
}

//BFS
private void bfs(int sx, int sy) {
    Queue<Integer>queue = new LinkedList<>();
    boolean []vis = new boolean[code(n,n)];
    vis[code(sx,sy)] = true;

    queue.add(code(sx,sy));
    while (!queue.isEmpty()){
        int cur = queue.remove();
        int x = cur / n, y = cur % n; //二维坐标转一维
        for(int k = 0; k < 4; k++)//四个方向拓展
        {
            int nextx = x + dirs[k][0];
            int nexty = y + dirs[k][1];
            if(InArea(nextx,nexty) && !vis[nextx*n+nexty]){
                if(grid[nextx][nexty] == 1){
                    //找到一个陆地即为到当前海洋的最近陆地
                    maxDis = Math.max(maxDis, getDis(sx,sy,nextx,nexty));
                    return;
                }
                vis[nextx*n+nexty] = true;//标记
                queue.add(code(nextx,nexty));
            }
        }
    }
}

//判断是否在区域内
private boolean InArea(int nextx, int nexty) {
    return nextx >= 0 && nexty < n && nextx < n && nexty >= 0;
}

//曼哈顿距离
private int getDis(int x1, int y1, int x2, int y2){
    return Math.abs(x1-x2)+Math.abs(y1-y2);
}

//二维转一维
private int code(int x, int y){
    return x*n+y;
}
```
