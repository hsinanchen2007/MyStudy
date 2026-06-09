```
class Solution {
    int xlen,ylen;
    public int longestIncreasingPath(int[][] matrix) {
        xlen = matrix.length;
        if(xlen==0) return 0;
        ylen = matrix[0].length;
        if(ylen==0) return 0;
        
        int res = 0;
        int[][] mem = new int[xlen][ylen];
        
        for(int i=0 ; i<xlen ; i++){
            for(int j=0 ; j<ylen ; j++){
                res = Math.max(dfs(matrix,mem,i,j,Integer.MIN_VALUE),res);
            }
        }
        return res;
    }
    
    public int dfs(int[][] matrix,int[][] mem,int x,int y,int pre){
        if(x<0 || x>=xlen || y<0 || y>=ylen || matrix[x][y]<=pre){
            return 0;
        }
        if(mem[x][y]>0) return mem[x][y];
        
        mem[x][y] = Math.max(Math.max(dfs(matrix,mem,x-1,y,matrix[x][y]),dfs(matrix,mem,x+1,y,matrix[x][y])),
                       Math.max(dfs(matrix,mem,x,y-1,matrix[x][y]),dfs(matrix,mem,x,y+1,matrix[x][y]))) + 1 ;
        
        return mem[x][y];
    }
}
```
