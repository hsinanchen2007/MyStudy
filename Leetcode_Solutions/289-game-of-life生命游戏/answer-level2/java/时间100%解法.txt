
1. 由于**细胞下一次存活状态依赖于目前状态**，因此定义一个和原二维数组大小相同的数组tempBoard用来存放细胞下一次的存活状态。
2. 遍历目前数组中的每一个细胞，**统计其周围八个细胞的存活个数**，判断其下存活状态并存入tempBoard中。
3. 遍历完成得到所有细胞下一次的存活状态，**将tempBoard拷贝回原数组**。

```
class Solution {
    public void gameOfLife(int[][] board) {
        if (board == null|| board.length == 0 || board[0] == null) {
            return;
        }
        int rowNum = board.length;
        int colNum = board[0].length;
        int[][] tempBoard = new int[rowNum][colNum];
        for (int i = 0; i < rowNum; i++) {
            for (int j = 0; j < colNum; j++) {
                int count = 0;
                // 左上
                if (i - 1 >= 0 && j - 1 >= 0 && board[i - 1][j - 1] == 1) {
                    count++;
                }
                // 上
                if (i - 1 >= 0 && board[i - 1][j] == 1) {
                    count++;
                }
                // 右上
                if (i - 1 >= 0 && j + 1 <= colNum - 1 && board[i - 1][j + 1] == 1) {
                    count++;
                }
                // 左
                if (j - 1 >= 0 && board[i][j - 1] == 1) {
                    count++;
                }
                // 右
                if (j + 1 <= colNum - 1 && board[i][j + 1] == 1) {
                    count++;
                }
                // 左下
                if (i + 1 <= rowNum - 1 && j - 1 >= 0 && board[i + 1][j - 1] == 1) {
                    count++;
                }
                // 下
                if (i + 1 <= rowNum - 1 && board[i + 1][j] == 1) {
                    count++;
                }
                // 右下
                if (i + 1 <= rowNum - 1 && j + 1 <= colNum - 1 && board[i + 1][j + 1] == 1) {
                    count++;
                }
                if (count < 2 || count > 3) {
                    continue;
                } else if (count == 3) {
                    tempBoard[i][j] = 1;
                } else {
                    tempBoard[i][j] = board[i][j];
                }
            }
        }
        for (int i = 0; i < rowNum; i++) {
            for (int j = 0; j < colNum; j++) {
                board[i][j] = tempBoard[i][j];
            }
        }
    }
}
```
