**1.DFS**
```java
    //后三个数字记录每个方向及可以连接的下一个街道的型号
    int[][] dires={{0,1,1,3,5},{1,0,2,5,6},{0,-1,1,4,6},{-1,0,2,3,4}};
    //记录每个街道哪些方向是通的
    int[][] cset= {{},{0,2},{1,3},{1,2},{0,1},{2,3},{0,3}};
    //DFS
    public boolean hasValidPath1(int[][] grid) {
        int m=grid.length, n=grid[0].length;
        return dfs(grid, new boolean[m][n], 0, 0);
    }
    boolean dfs(int[][] grid, boolean[][] visited, int x, int y){
        int m=grid.length, n=grid[0].length;
        if(x==m-1 && y==n-1) return true;
        visited[x][y]=true;
        int[] rdires=cset[grid[x][y]];
        for(int rd:rdires){
            int[] d=dires[rd];
            int x1=x+d[0], y1=y+d[1];
            if(x1>=m || x1<0 || y1>=n || y1<0 || visited[x1][y1]) continue;
            if(grid[x1][y1]==d[2] || grid[x1][y1]==d[3] || grid[x1][y1]==d[4]){
               if(dfs(grid,visited,x1,y1)) return true;
            }
        }
        return false;
    }
```
**2.BFS**
```java
    public boolean hasValidPath(int[][] grid) {
        int m=grid.length, n=grid[0].length;
        boolean[][] reach=new boolean[m][n];
        Queue<int[]> queue = new LinkedList<>();
        queue.add(new int[]{0,0,1});
        while (!queue.isEmpty()){
            int[] cur=queue.poll();
            if(cur[0]==m-1 && cur[1]==n-1) return true;
            int[] rdires=cset[grid[cur[0]][cur[1]]];
            for(int rd:rdires){
                int[] d=dires[rd];
                int x=cur[0]+d[0], y=cur[1]+d[1];
                if(x>=m || x<0 || y>=n || y<0 || reach[x][y]) continue;
                if(grid[x][y]==d[2] || grid[x][y]==d[3] || grid[x][y]==d[4]){
                    queue.add(new int[]{x, y, 1});
                    reach[x][y]=true;
                }
            }

        }

        return false;
    }
```
