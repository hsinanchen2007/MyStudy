```
class Solution {
    public void gameOfLife(int[][] board) {
        int i = 0, j = 0, k = 0;
        int m = board.length, n = board[0].length;
        int[][] res = new int[m][n];
        for(i=0; i<m; i++){
            for(j=0; j<n; j++){
                res[i][j] = board[i][j];
            }
        }

        //方向数组，上下左右，右上、左上、右下、左下
        int[] dx = {0, 0, -1, 1, -1, 1, -1, 1};
        int[] dy = {-1, 1, 0, 0, -1, -1, 1, 1};
        int count = 0;
        for(i=0; i<m; i++){
            for(j=0; j<n; j++){
                count = 0;
                for(k=0; k<8; k++){
                    int x = i+dx[k];
                    int y = j+dy[k];
                    if(x<0 || x>=m || y<0 || y>=n){
                        continue;
                    }
                    if(res[x][y]==1){
                        count++;
                    }
                }

                if(res[i][j] == 0 && count == 3){
                    board[i][j] = 1;
                }
                if(res[i][j] == 1 && (count<2 || count>3) ){
                    board[i][j] = 0;
                }
            }
        }

    }
}
```
