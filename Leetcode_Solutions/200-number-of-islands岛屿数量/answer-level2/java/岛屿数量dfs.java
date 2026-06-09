深度优先遍历
```
class Solution {
    private int[][] des={{-1,0},{0,1},{1,0},{0,-1}};
    private int number;
    class Position{
        int x,y;
        Position(int x,int y){
            this.x=x;
            this.y=y;
        }
        int getX(){
            return x;
        }
        int getY(){
            return y;
        }
    }
    //本质求联通分量
    public int numIslands(char[][] grid) {
        if(grid==null||grid.length==0){
            return 0;
        }
        boolean[][]  visited=new boolean[grid.length][grid[0].length];
        while(!dfs(visited,grid)){
            number++;
        }
        return number;
    }
    //求联通分量
    public boolean dfs(boolean[][] visited,char[][] grid){
        boolean isok=false;
        Stack<Position> stack=new Stack();
        for(int i=0;i<grid.length;i++){
            for(int j=0;j<grid[i].length;j++){
                if(grid[i][j]=='1'&&!visited[i][j]){
                    stack.push(new Position(i,j));
                    isok=true;
                    break;
                }
            }
              if(isok){
                    break;
                }
        }
        if(stack.isEmpty()){
            return true;
        }
        while(!stack.isEmpty()){
            Position cur=stack.pop();
            visited[cur.getX()][cur.getY()]=true;
            for(int i=0;i<4;i++){
                int newX=cur.getX()+des[i][0];
                int newY=cur.getY()+des[i][1];
                if(isIlleagl(grid,newX,newY)&&grid[newX][newY]=='1'&&!visited[newX][newY]){
                    stack.push(new Position(newX,newY));
                }
            }
        }
        return false;
        
    }
    //判断下标是否合法
    public boolean isIlleagl(char[][] grid,int x,int y){
        return x>=0&&x<grid.length&&y>=0&&y<grid[0].length;
    }
}
```
