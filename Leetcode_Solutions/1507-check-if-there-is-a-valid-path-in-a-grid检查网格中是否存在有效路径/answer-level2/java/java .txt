```
class Solution {
    boolean ret= false;
    public boolean hasValidPath(int[][] grid) {
        dfs(grid,0,0,0);
        return ret;
    }
    
    //last = 0,1上,2下,3左,4右
    public void dfs(int[][] g, int x, int y,int last){
        // System.out.println(x+" "+y+" "+" "+last);
        if(x<0 || x>g.length-1 || y<0 || y>g[0].length-1){
            if(g[g.length-1][g[0].length-1] == -1){
                ret = true;
            }
            return ;
        }
        int way = g[x][y];
        g[x][y] = -1;
        switch (way){
            case 1:
                if(last == 0 || last == 3){
                    dfs(g,x,y+1,3);
                }else if(last == 4){
                    dfs(g,x,y-1,4);
                }else{
                    return ;
                }
                break;
            case 2:
                if(last == 0 || last == 1){
                    dfs(g,x+1,y,1);
                }else if(last == 2){
                    dfs(g,x-1,y,2);
                }else{
                    return ;
                }
                
                break;
            case 3:
                if(last == 0 || last == 3){
                    dfs(g,x+1,y,1);
                }else if(last == 2){
                    dfs(g,x,y-1,4);
                }else{
                    return ;
                }
                break;
            case 4:
                if(last == 0 ){
                    dfs(g,x,y+1,3);
                    dfs(g,x+1,y,1);
                }else if(last == 2){
                    dfs(g,x,y+1,3);
                }else if(last == 4){
                    dfs(g,x+1,y,1);
                }else{
                    return ;
                }
                break;
            case 5:
                if( last == 1){
                    dfs(g,x,y-1,4);
                }else if(last == 3){
                    dfs(g,x-1,y,2);
                }else{
                    return ;
                }
                break;
            case 6:
                if(last == 0 || last == 1){
                    dfs(g,x,y+1,3);
                }else if(last == 4){
                    dfs(g,x-1,y,2);
                }else{
                    return ;
                }
                break;
            case -1://重复
                return ;
        }
        
    }
}
```
