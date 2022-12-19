本来使用的boolean数组，发现替换成int数组用01代表是否后，速度提高了不少
```
class Solution {
    public boolean isValidSudoku(char[][] board) {
        int[][][] smallBox = new int[3][3][9];
        int[][] rows = new int[9][9];
        int[][] cols = new int[9][9];
        for(int i = 0; i < 9; i++) {
            for(int j = 0; j < 9; j++) {
                if(board[i][j] == '.') continue;
                int num = board[i][j] - '1';
                if(smallBox[i/3][j/3][num]==1 || rows[i][num]==1 || cols[num][j]==1){
                    return false;
                }
                else {
                    smallBox[i/3][j/3][num] = 1;
                    rows[i][num] = 1;
                    cols[num][j] = 1;
                }
            }
        }
        return true;
    }
}
```
