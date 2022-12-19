```
class Solution {
    public void gameOfLife(int[][] board) {
        if(board == null)
            return ;
        int r = board.length;
        if(r == 0)
            return ;
        int c = board[0].length;
        int[][] temp = new int[r+2][c+2];
        // 在上下左右填充一层，这是个有用的技巧
        for(int i = 1;i < r+1;i++){
            for(int j = 1;j < c+1;j++){
                temp[i][j] = board[i-1][j-1];
            }
        }
        for(int i = 1;i < r+1;i++){
            for(int j = 1;j < c+1;j++){
                //判断周围细胞决定状态
                int sum = 0;
                sum += temp[i-1][j-1];
                sum += temp[i-1][j];
                sum += temp[i-1][j+1];
                sum += temp[i][j-1];
                sum += temp[i][j+1];
                sum += temp[i+1][j-1];
                sum += temp[i+1][j];
                sum += temp[i+1][j+1];
                
                if(sum < 2 || sum > 3){
                    board[i-1][j-1] = 0;
                }
                else{
                    if(sum == 3 && board[i-1][j-1] == 0){
                        board[i-1][j-1] = 1;
                    }
                }
            }
        }
    }
    
}
```
