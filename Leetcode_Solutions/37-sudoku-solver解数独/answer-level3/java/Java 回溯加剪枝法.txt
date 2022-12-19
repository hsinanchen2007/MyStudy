

```
class Solution {
    public void solveSudoku(char[][] board) {
        
        if (board == null || board.length == 0) {
            return;
        } 
        
        solve(board);
        
    }
    
    public boolean solve(char[][] board) {
        
        for (int i = 0; i < board.length; i++) {
            for (int j = 0; j < board[0].length; j++) {
                
                if (board[i][j] == '.') {
                    for (char c = '1'; c <= '9'; c++) {
                        if (isValid(board, i, j, c)) {
                            board[i][j] = c;
                            // 递归退出条件
                            if (solve(board)) {
                                return true;
                            } else {
                                // 恢复现场
                                board[i][j] = '.'; 
                            }  
                        } 
                        
                    }
                    // 没有结果说明不能退出
                    return false;
                }       
            } 
        }
        // 全部循环结束应该退出
        return true;
        
    }
    
    public boolean isValid(char[][] board, int row, int col, char c) {
        for (int i = 0; i < 9; i++) {
            if (board[i][col] != '.' && board[i][col] == c) {
                return false;
            }
            
            if (board[row][i] != '.' && board[row][i] == c) {
                return false;
            }
            
            if (board[3 * (row / 3)  + i / 3 ][3 * (col / 3) + i % 3] != '.' &&
               board[3 * (row / 3)  + i / 3 ][3 * (col / 3) + i % 3] == c) {
                return false;
            }
        }
        
        return true;
    }
}
```
