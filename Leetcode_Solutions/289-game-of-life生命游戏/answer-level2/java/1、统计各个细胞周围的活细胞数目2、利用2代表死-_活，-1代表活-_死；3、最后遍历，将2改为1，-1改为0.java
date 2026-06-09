### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public void gameOfLife(int[][] board) {

        // 本题考查内存溢出问题

        int rowLen = board.length;
        int colLen = board[0].length;

        for (int i = 0; i < rowLen; i++) {
            for (int j = 0; j < colLen; j++) {
                int beginRow = i > 0 ? i - 1 : i;
                int endRow = i < rowLen - 1 ? i + 1 : i;
                int beginCol = j > 0 ? j - 1 : j;
                int endCol = j < colLen - 1 ? j + 1 : j;
                int liveGameCount = statisticLiveGame(beginRow, endRow, beginCol, endCol, board);
                if (board[i][j] == 1) {
                    liveGameCount--;
                    if (liveGameCount != 2 && liveGameCount != 3) {
                        board[i][j] = -1;
                    }
                } else {
                    if (liveGameCount == 3) {
                        board[i][j] = 2;
                    }
                }
            }
        }

        for (int i = 0; i < rowLen; i++) {
            for (int j = 0; j < colLen; j++) {
                if (board[i][j] == -1) {
                    board[i][j] = 0;
                } else if (board[i][j] == 2) {
                    board[i][j] = 1;
                }
            }
        }

    }

    // 只需要统计原始矩阵中，某个细胞周围活着的细胞数
    private int statisticLiveGame(int beginRow, int endRow, int beginCol, int endCol, int[][] board) {
        int liveGameCount = 0;
        for (int i = beginRow; i <= endRow; i++) {
            for (int j = beginCol; j <= endCol; j++) {
                if (board[i][j] == 1 || board[i][j] == -1) {
                    liveGameCount++;
                }
            }
        }
        return liveGameCount;
    }

    
}
```