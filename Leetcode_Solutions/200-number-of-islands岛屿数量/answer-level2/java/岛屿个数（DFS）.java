岛屿个数(DFS)
//参考别人的
```java
class Solution {
    int cols;
    int rows;
    boolean[][] marked;
    int[][] directions={{-1,0},{0,1},{1,0},{0,-1}};//坐标向上，下，左，右延伸
    char[][] grids;
    
    //DFS
    public int numIslands(char[][] grid) {
        int count=0;
        rows=grid.length;
        if(rows==0) return count;
        cols=grid[0].length;
        marked=new boolean[rows][cols];
        this.grids=grid;
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(grids[i][j]=='1'&&!marked[i][j]){
                   count++;
                   DFS(i,j);
                }
            }
        }

        return count;

    }
    public boolean isArea(int x,int y){
        return x>=0&&x<rows&&y<cols&&y>=0;
    }

    public void DFS(int i,int j){
        marked[i][j]=true;
        for(int k=0;k<4;k++){
            int newX=i+directions[k][0];
            int newY=j+directions[k][1];
            if(isArea(newX,newY)&&grids[newX][newY]=='1'&&!marked[newX][newY]){
                DFS(newX,newY);
            }
        }
    }

}
```