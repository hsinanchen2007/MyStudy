执行用时 :6 ms, 在所有 java 提交中击败了93.45% 的用户
内存消耗 :38.7 MB, 在所有 java 提交中击败了97.16%的用户
```
class Solution {
    public boolean exist(char[][] board, String word) {
        if(board == null || board.length < 1 || board[0].length < 1 || word == null || word.length() < 1)
            return false;
        int row = board.length;
        int col = board[0].length;
        boolean[][] flag = new boolean[row][col];
        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                if(getResult(board, flag, row, col, i, j, 0, word)){
                    return true;
                }
            }
        }
        return false;
    }
    public boolean getResult(char[][] board, boolean[][] flag, int row, int col, int i, int j, int start, String word){
        if(i < 0 || i >= row || j < 0 || j >= col || flag[i][j] || start >= word.length() || board[i][j] != word.charAt(start)){
            return false;
        }
        start++;
        if(start == word.length())
            return true;
        flag[i][j] = true;
        if(getResult(board, flag, row, col, i, j-1, start, word) || 
           getResult(board, flag, row, col, i-1, j, start, word) ||
           getResult(board, flag, row, col, i, j+1, start, word) || 
           getResult(board, flag, row, col, i+1, j, start, word)){
           flag[i][j] = false;
           return true;
        }
        flag[i][j] = false;
        return false;
    }
}
```
