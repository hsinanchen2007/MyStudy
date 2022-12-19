```
public int movingCount(int m, int n, int k)
    {
        boolean[][] visited=new boolean[m][n];
        return movingCountCore(k, m, n, 0,0,visited);
    }
    private int movingCountCore(int threshold, int rows, int cols,
            int row,int col,boolean[][] visited) {
        if(row<0||row>=rows||col<0||col>=cols) return 0;
        //int i=row*cols+col;
        if(visited[row][col]||!checkSum(threshold,row,col)) return 0;
        visited[row][col]=true;
        return 1+movingCountCore(threshold, rows, cols,row,col+1,visited)
                +movingCountCore(threshold, rows, cols,row,col-1,visited)
                +movingCountCore(threshold, rows, cols,row+1,col,visited)
                +movingCountCore(threshold, rows, cols,row-1,col,visited);
    }
    private boolean checkSum(int threshold, int row, int col) {
        int sum=0;
        while(row!=0){
            sum+=row%10;
            row=row/10;
        }
        while(col!=0){
            sum+=col%10;
            col=col/10;
        }
        if(sum>threshold) return false;
        return true;
    }
```
