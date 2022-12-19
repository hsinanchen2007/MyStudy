### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public static void gameOfLife(int[][] board) {
        if (board == null) {
            return;
        }
        int ROW = board.length;
        int COL = board[0].length;
        int[][] process = new int[ROW][COL];
        int[][] direction = new int[][] {{1, 0}, {-1, 0}, {0, 1}, {0, -1}, {1, 1}, {1, -1}, {-1, -1}, {-1, 1}};
        int newRow = -1;
        int newCol = -1;
        for (int i = 0; i < board.length; i++) {
            for (int j = 0; j < board[0].length; j++) {
                generateLife(i, j, process, board);
            }
        }
        copyToboad(process, board);
    }

    private static void copyToboad(int[][] process, int[][] board) {
        for (int i = 0; i < board.length; i++) {
            for (int j = 0; j < board[0].length; j++) {
                board[i][j] = process[i][j];
            }
        }
    }

    private static void generateLife(int x, int y, int[][] process, int[][] board) {
        int ROW = board.length;
        int COL = board[0].length;
        int newRow = 0;
        int newCol = 0;
        int[][] direction = new int[][] {{1, 0}, {-1, 0}, {0, 1}, {0, -1}, {1, 1}, {1, -1}, {-1, -1}, {-1, 1}};
        int sum = 0;
        for (int i = 0; i < 8; i++) {
            newRow = x + direction[i][0];
            newCol = y + direction[i][1];
            if (newRow >= 0 && newRow < ROW && newCol >= 0 && newCol < COL) {
                sum = sum + board[newRow][newCol];
            }
        }
        generateProcess(board,process,sum,x,y);
    }
    private static void generateProcess(int[][] board, int[][] process, int sum, int x, int y){
        if ((board[x][y] == 1) && (sum < 2 || sum > 3)) {
            process[x][y] = 0;
        } else if (sum == 3) {
            process[x][y] = 1;
        } else {
            process[x][y] = board[x][y];
        }
    }
}
```