

两步法-1 找到岛屿的一个点
      2 标记这个点周围的点为已经访问过，避免重复计数




```java []
        public static int numIslands(char[][] grid) {
        boolean[][] visited = new boolean[grid.length][grid[0].length];
       // System.out.print(visited[0][0]);
        int sum=0;
        for(int i=0;i<grid.length;i++){

            for (int j=0;j<grid[0].length;j++){
               // System.out.print(
                if(grid[i][j]=='1'&&!visited[i][j]){
                 //   System.out.print(i+" "+j+"\n");
                    sum++;
                    //visited[i][j]=true;
                    mark(visited,i,j,grid);
                }
            }

        }
        return sum;
    }
    public static void mark(boolean[][] visited,int i,int j,char[][] grid){
        visited[i][j]=true;
        if (i<0||i>grid.length||j<0||j>grid[0].length-1)
            return;

        if(i-1>=0&&grid[i-1][j]=='1'&&!visited[i-1][j]){
           // visited[i-1][j]=true;
            mark(visited,i-1,j,grid);
        }
        if(i+1<grid.length&&grid[i+1][j]=='1'&&!visited[i+1][j]){
            //visited[i+1][j]=true;
            mark(visited,i+1,j,grid);
        }
        if(j-1>=0&&grid[i][j-1]=='1'&&!visited[i][j-1]){
           // visited[i][j-1]=true;
            mark(visited,i,j-1,grid);
        }
        if(j+1<grid[0].length&&grid[i][j+1]=='1'&&!visited[i][j+1]){
           // visited[i][j+1]=true;
            mark(visited,i,j+1,grid);
        }

return;
    }
```

