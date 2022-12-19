![image.png](https://pic.leetcode-cn.com/2c910c87114652970934e06d06b7f3d131eb2503f7f5a19e828ebfedf5bed349-image.png)

方法就是检查每行每列是否每个九宫格是否有重复值。
```
class Solution {
    public boolean isValidSudoku(char[][] board) {
            if(board == null || board.length <= 1){
                return false;
            }
            for(int i = 0;i < board.length;i++){
                for(int j = 0;j < board[0].length;j++){
                    if(board[i][j] != '.'){
                         if(!isValidHelp(board, board[i][j], i, j)){
                             return false;
                         }
                    }
                }
            }
            return true;
    }


    public boolean isValidHelp(char[][] board,char c,int row,int column){
            
            if(board == null) return false;
            
            for(int i = 0;i < row;i++){
                if(board[i][column] == c && i != row){
                    return false;
                }
            }
            for(int i = 0;i < column;i++){
                if(board[row][i] == c && i != column){
                    return false;
                }
            }
        
            int n = row/3;
            int m = column/3;

            //注意这里 *3 + 3  开始没注意我合并成 n*4 了 卡了很久
            for(int i = n * 3;i < n * 3 + 3;i++){
                for(int j = m * 3;j < m * 3 + 3;j++){
                        if(board[i][j] == c ){
                            //判断是否是自己
                            if(i != row && j != column){
                                return false;
                            }
                        }
                }
            }
            return true;
    }
}
```
