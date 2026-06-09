```
class Solution {
    public boolean isValidSudoku(char[][] board) {
        int[][] rows = new int[9][10];
        int[][] columns = new int[9][10];
        int[][] boxes = new int[9][10];
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                char num = board[i][j];
                if (num != '.') {
                    int n = num-'0';
                    int box_index = (i / 3 ) * 3 + j / 3;
                    rows[i][n]++;
                    columns[j][n]++;
                    boxes[box_index][n]++;
                    if(rows[i][n]>1||columns[j][n]>1||boxes[box_index][n]>1) return false;
                }
            }
        }
        return true;
    }
}

```
