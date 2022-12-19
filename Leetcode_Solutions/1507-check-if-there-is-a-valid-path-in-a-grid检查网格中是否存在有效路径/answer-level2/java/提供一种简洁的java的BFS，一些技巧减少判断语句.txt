题目的思路相信很多题解都已经解答的很完美了，这里提供一种BFS的方法技巧
通过设置index索引数组，和vis数组，不用多情况判断
1上 2左 3下 4右
30行代码
```
class Solution {
    int[][] dir={{0,0},{-1,0},{0,-1},{1,0},{0,1}};
    boolean[][] vis;
    int n,m;
    int[][] index={{0,0},{2,4},{1,3},{2,3},{3,4},{1,2},{1,4}};
    public boolean hasValidPath(int[][] grid) {
        n=grid.length;
        m=grid[0].length;
        vis=new boolean[n][m];
        Queue<int[]> q=new LinkedList<>();
        q.add(new int[]{0,0});
        vis[0][0]=true;
        while(!q.isEmpty()){
            int[] u=q.poll();
            if(u[0]==n-1&&u[1]==m-1) return true;
            int x=u[0],y=u[1];
            for(int i=0;i<2;i++){
                int d=index[grid[x][y]][i];
                int nx=x+dir[d][0];
                int ny=y+dir[d][1];
                if(nx<0||nx>=n||ny<0||ny>=m||vis[nx][ny]) continue;
                int nd=(d+2)>4?d+2-4:d+2;
                if(index[grid[nx][ny]][0]!=nd&&index[grid[nx][ny]][1]!=nd) continue;
                vis[nx][ny]=true;
                q.add(new int[]{nx,ny});
            }
        }
        return false;
    }
}
```