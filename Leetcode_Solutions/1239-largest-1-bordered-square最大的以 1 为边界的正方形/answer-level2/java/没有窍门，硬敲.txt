```
public int largest1BorderedSquare(int[][] grid) {
        int len=grid.length,llen=grid[0].length;
        int[][][] dp=new int[len][llen][2];
        int max=0;
        int[][] dir=new int[][]{{-1,0},{0,-1},{0,1},{1,0}};
        for (int i=0;i<len;i++){
            for (int j=0;j<llen;j++){
                if(grid[i][j]==1){
                    dp[i][j][0]=1;
                    dp[i][j][1]=1;
                    max=Math.max(max,1);
                    int a=len,b=len;
                    for (int d=0;d<2;d++){
                        int step=0;
                        int nx=i+dir[d][0],ny=j+dir[d][1];
                        while ((nx>=0&&nx<len)&&(ny>=0&&ny<llen)&&grid[nx][ny]==1){
                            step++;
                            nx+=dir[d][0];
                            ny+=dir[d][1];
                        }
                        a=Math.min(a,step);
                    }
                    for (int d=2;d<4;d++){
                        int step=0;
                        int nx=i+dir[d][0],ny=j+dir[d][1];
                        while ((nx>=0&&nx<len)&&(ny>=0&&ny<llen)&&grid[nx][ny]==1){
                            step++;
                            nx+=dir[d][0];
                            ny+=dir[d][1];
                        }
                        b=Math.min(b,step);
                    }
                    dp[i][j][0]=1+a;
                    dp[i][j][1]=1+b;
                    for (int l=a;l>0;l--){
                        if(i-l>=0&&j-l>=0&&dp[i-l][j-l][1]>=(1+l)){
                            max=Math.max(max,(1+l)*(1+l));
                        }
                    }
                }
            }
        }
        return max;
    }
```
