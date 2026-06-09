### 解题思路
不适用额外的存储空间。如果细胞从0变为1，则将其值置为2；如果细胞从1变为0，则将其值置为3。那么他们以模2取余后的值，即为原来的值。这样虽然数值改变了，并不影响计算其他细胞的更新。计算完成后，再将具有这些特殊状态的值还原为原有的值。

### 代码

```java
class Solution {

    private final int[][] directions = new int[][]{{1,0},{-1,0},{0,1},{0,-1},{-1,1},{-1,-1},{1,1},{1,-1}};
    private int[][] board;
    // 0->1 2, 1->0 3

    public void gameOfLife(int[][] board) {
        this.board = board;
        int count = 0;
        for (int i = 0; i < board.length; i ++) {
            for (int j = 0; j < board[i].length; j ++) {
                count = aliveCount(i, j);
                if (board[i][j] == 1 && count < 2) {
                    board[i][j] = 3;
                }
                if (board[i][j] == 1 && (count == 2 || count == 3)) {
                    board[i][j] = 1;
                }
                if (board[i][j] == 1 && count > 3) {
                    board[i][j] = 3;
                }
                if (board[i][j] == 0 && count == 3) {
                    board[i][j] = 2;
                }
            }
        }

        for (int i = 0; i < board.length; i ++) {
            for (int j = 0; j < board[i].length; j ++) {
                if (board[i][j] < 2) continue;
                board[i][j] = (board[i][j] + 1) % 2;
            }    
        }
    }

    private int aliveCount(int i, int j) {
        int x = 0, y = 0, count = 0;
        for (int k = 0; k < directions.length; k ++) {
            x = i + directions[k][0];
            y = j + directions[k][1];
            if (x >= 0 && x < board.length && y >= 0 && y < board[x].length) {
                count += board[x][y] % 2;
            }
        }
        return count;
    }
}
```