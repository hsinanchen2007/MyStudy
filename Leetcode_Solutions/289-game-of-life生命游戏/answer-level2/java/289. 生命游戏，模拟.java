### 解题思路
由于每个格子只能为`0（0）`或者`1（1）`，那么在计算周围格子的时候直接加上`2（二进制为10）`，保留最后一位的数据就好了。

这题我也不知道为什么评测系统原地操作的内存耗费居然比开了一个辅助数组大。
![Screen Shot 2020-04-02 at 16.18.46.png](https://pic.leetcode-cn.com/33dde7a0a4de7fb76cbe4fdeac0c425f2b7e5f573960e37c157029f72d0662ac-Screen%20Shot%202020-04-02%20at%2016.18.46.png)


### 代码
```java
class Solution {
    public void gameOfLife(int[][] board) {
        // int[][] newBoard = new int[board.length][board[0].length];
        int[] dx = new int[] {0, 0, -1, 1, -1, -1, 1, 1};
        int[] dy = new int[] {-1, 1, 0, 0, -1, 1, -1, 1};
        for (int x = 0; x < board.length; ++x) {
            for (int y = 0; y < board[0].length; ++y) {
                if (board[x][y] % 2 == 0) continue;
                for (int k = 0; k < dx.length; ++k) {
                    int adjX = x + dx[k];
                    int adjY = y + dy[k];
                    if (adjX < 0 || adjX >= board.length) continue;
                    if (adjY < 0 || adjY >= board[0].length) continue;
                    // newBoard[adjX][adjY] ++;
                    board[adjX][adjY] += 2;
                }
            }
        }

        for (int x = 0; x < board.length; ++x) {
            for (int y = 0; y < board[0].length; ++y) {
                int liveCell = board[x][y] >> 1;
                // System.out.print(liveCell + ":");
                if ((board[x][y] & 1) == 1) {
                    if (liveCell < 2) {
                        board[x][y] = 0;
                    } else if (liveCell <= 3) {
                        board[x][y] = 1;
                    } else {
                        board[x][y] = 0;
                    }
                } else {
                    if (liveCell == 3) {
                        board[x][y] = 1;
                    } else {
                        board[x][y] = 0;
                    }
                }
                // System.out.print(board[x][y] + " ");
            }
            // System.out.println();
        }
    }
}
```