```
class Solution {
    //访问标志
    private boolean [][]visted;
    int count = 0;
    char[][] iland;
    public int numIslands(char[][] grid) {
        if(grid.length<1){
            return 0;
        }
        iland = grid;
        visted =new boolean[grid.length][grid[0].length];
        for(int  i=0;i<grid.length;i++){
            for(int j=0;j<grid[0].length;j++){
                if(!visted[i][j] && grid[i][j]=='1'){
                    count++;
                    dfs(i,j);
                }else{
                    continue;
                }
            }
        }
        return count;
    }
    //遍历四个方向
    public void dfs(int x,int y){
        visted[x][y] = true;
         if(judge(x-1,y)){
             dfs(x-1,y);
         }  
         if(judge(x+1,y)){
             dfs(x+1,y);
         }
         
        if(judge(x,y-1)){
             dfs(x,y-1);
         }
        if(judge(x,y+1)){
             dfs(x,y+1);
         }
    }
    public boolean judge(int x,int y){
        if(0<=x&&x<iland.length&&0<=y&&y<iland[0].length&&!visted[x][y]&&iland[x][y]=='1')
            return true;
        else
            return false; 
    }
}
```
