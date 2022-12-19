遍历回溯
代码：
```
import java.util.*;
class Solution {
    final int L = 9;
    public void solveSudoku(char[][] board) {
        //0未被占用，1被占用
        int[][] row = new int[L][L + 1];
        int[][] col = new int[L][L + 1];
        int[][] nineGrid = new int[L][L + 1];
        for(int i = 0; i < L; i++) {
            for(int j = 0; j < L; j++) {
                if(board[i][j] != '.') {
                    int num = board[i][j] - '0';
                    row[i][num] = 1;
                    col[j][num] = 1;
                    int block = 3 * (i / 3);
                    block += j/3;
                    nineGrid[block][num] = 1;
                }
            }
        }
        solve(row, col, nineGrid, board, 0);

    }

    public boolean solve(int[][] row, int[][] col, int[][] nineGrid, char[][] board, int index) {
        if(index == 81) return true;
        int i = index / 9;
        int j = index % 9;
        if(board[i][j] != '.') {
            return solve(row, col, nineGrid, board, index + 1);
        }else {
            int block = 3 * (i / 3);
            block += j/3;
            for(int k = 1; k <= L; k++) {
                if(row[i][k] == 0 && col[j][k] == 0 && nineGrid[block][k] == 0) {
                    board[i][j] = (char)(k + '0');
                    row[i][k] = 1;
                    col[j][k] = 1;
                    nineGrid[block][k] = 1;
                    if(solve(row, col, nineGrid, board, index + 1))
                        return true;
                    board[i][j] = '.';
                    row[i][k] = 0;
                    col[j][k] = 0;
                    nineGrid[block][k] = 0;
                }
            }
            return false;
        }

    }
}
```
![截屏2020-01-09下午5.26.57.png](https://pic.leetcode-cn.com/db2cb14aa09faba9a1ebac5bb5f4bb5dd581438794d6cbb9ec0552cd5cc405ba-%E6%88%AA%E5%B1%8F2020-01-09%E4%B8%8B%E5%8D%885.26.57.png)
