class Solution {
    
    public int orangesRotting(int[][] grid) {
        int time=0;
        if (grid.length==0) return 0;
        int change=0;
        int tmp;
        int[][] used=new int[grid.length][grid[0].length];
        for(int i=0;i<grid.length;i++){
            for(int j=0;j<grid[0].length;j++){
                used[i][j]=0;
                if(grid[i][j]==1) change++;
            }
        }
        do{
            tmp=change;
            for(int i=0;i<grid.length;i++){
                for(int j=0;j<grid[i].length;j++){
                    if(used[i][j]==time&&grid[i][j]==2) change-=changevalue(used,grid,i,j,time);
                }
            }
            time++;
        }while (tmp!=change);
        if(change==0) return time-1;
        else return -1;
    }
    private int changevalue(int[][] used,int[][] grid,int i,int j,int time){
        int num=0;
        if(i-1>=0&&grid[i-1][j]==1) {
            num++;
            grid[i-1][j]=2;
            used[i-1][j]=time+1;
        }
        if(j-1>=0&&grid[i][j-1]==1) {
            num++;
            grid[i][j-1]=2;
            used[i][j-1]=time+1;
        }
        if(i+2<=grid.length&&grid[i+1][j]==1) {
            num++;
            grid[i+1][j]=2;
            used[i+1][j]=time+1;
        }
        if(j+2<=grid[i].length&&grid[i][j+1]==1) {
            num++;
            grid[i][j+1]=2;
            used[i][j+1]=time+1;
        }
        return num;
    }
}