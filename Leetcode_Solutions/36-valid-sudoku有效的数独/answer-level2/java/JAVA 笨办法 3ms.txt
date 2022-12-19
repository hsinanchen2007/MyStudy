解题思路：横、竖、9格内扫描一遍 😄

![image.png](https://pic.leetcode-cn.com/af0cc6d03c72aa14d632d69418b63a7d979a969cffc984c1edaf0925c94bbba9-image.png)



```
  public boolean isValidSudoku(char[][] board) {
        for (int i = 0;i < 9;i++) {
            for (int j = 0;j < 9;j++) {
                if (board[i][j] == '.') continue;
                boolean b = checkExist(i, j, board);
                if (b) {
                    return false;
                }
            }
        }
        return true;
    }

    private boolean checkExist(int m,int n,char[][] board){
        boolean res = false;
        for (int i = 0;i < 9;i++) {
            if (board[m][i] == board[m][n] && i != n) {
                return true;
            }
            if (board[i][n] == board[m][n] && i != m) {
                return true;
            }

            for (int p = m / 3 * 3;p < m / 3 * 3 + 3;p++) {
                for (int q = n / 3 * 3;q < n / 3 * 3 + 3;q++) {
                    if (board[p][q] == board[m][n] && p != m && q != n) {
                        return true;
                    }
                }
            }
        }
        return res;
    }
```
