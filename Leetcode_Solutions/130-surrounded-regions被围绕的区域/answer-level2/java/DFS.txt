执行用时 :2 ms, 在所有 java 提交中击败了99.34% 的用户
内存消耗 :41 MB, 在所有 java 提交中击败了89.77%的用户
```
class Solution {
    public void solve(char[][] board) {
        if(board == null || board.length < 1 || board[0].length < 1)
            return;
        int row = board.length;
        int col =  board[0].length;
        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                if(board[i][j] == 'O' && (i == 0 || i == row-1 || j == 0 || j == col-1)){
                    solveCore(board, row, col, i, j);
                }
            }
        }
        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                if(board[i][j] == 'O'){
                    board[i][j] = 'X';
                }
                if(board[i][j] == '#'){
                    board[i][j] = 'O';
                }
            }
        }
    }
    public void solveCore(char[][] board, int row, int col, int i, int j) {
		if(i < 0 || i >= row || j < 0 || j >= col || board[i][j] == 'X' || board[i][j] == '#')
            return;
		board[i][j] = '#';
		solveCore(board, row, col, i, j - 1);
		solveCore(board, row, col, i - 1, j);
		solveCore(board, row, col, i, j + 1);
		solveCore(board, row, col, i + 1, j);
	}
}
```
