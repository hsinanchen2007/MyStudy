### 解题思路
正常思路，就是将原数组复制一份得到`copyBoard`，然后遍历`copyBoard`，对于每一个位置按照生存定律，判断其生存状态，再更新原数组对应位置上的值。

```java
class Solution {
    public void gameOfLife(int[][] board) {
        int[][] copyBoard = new int[board.length][board[0].length];
        copyArray(board, copyBoard);
        for (int i = 0; i < board.length; i++) {
            for (int j = 0; j < board[i].length; j++) {
                board[i][j] = updateStatus(copyBoard, i, j);
            }
        }
    }

    // 复制数组 
    private void copyArray(int[][] board, int[][] copyBoard) {
        for (int i = 0; i < board.length; i++) {
            for (int j = 0; j < board[i].length; j++) {
                copyBoard[i][j] = board[i][j];
            }
        }
    }

    // 按生存定律更新细胞状态
    private int updateStatus(int[][] board, int x, int y) {
        // 某个细胞周围活细胞数目 
        int livingCount = 0;
        for (int i = x - 1; i <= x + 1; i++) {
            for (int j = y - 1; j <= y + 1; j++) {
                if (i >= 0 && i < board.length && j >= 0 && j < board[0].length && board[i][j] == 1) {
                    livingCount++;
                }
            }
        }
        // 减掉当前位置重复计算的值
        livingCount -= board[x][y];
        if (board[x][y] == 1) {
            if (livingCount < 2 || livingCount > 3) {
                return 0;
            } else {
                return 1;
            }
        } else {
            if (livingCount == 3) {
                return 1;
            } else {
                return 0;
            }
        }
    }
}
```

原地更新的话也不难，首先我们可以想一下我们一开始为什么先复制一个数组，是因为我们想到如果直接更新原数组某个位置上的值，会影响其他位置的**同步更新**，说具体点就是我们一次次更新原数组的时候，把之前位置上的信息丢失了（比如一开始是`0`，然后经过生存定律变成`1`），这个时候再判断其相邻位置的状态，显然会得出错误结论。

那么我们要做的就是在更新的时候，不仅要保留更新后的状态，也要保留更新前的状态，所以我们可以定义新的状态值：
- **0**：更新前后都是死细胞
- **1**：更新前后都是活细胞
- **2**：更新前是活细胞，更新后是死细胞
- **3**：更新前是死细胞，更新后是活细胞

判断状态的时候，多考虑一个就行了。

```java
class Solution {
    public void gameOfLife(int[][] board) {
        for (int i = 0; i < board.length; i++) {
            for (int j = 0; j < board[i].length; j++) {
                board[i][j] = updateStatus(board, i, j);
            }
        }
        for (int i = 0; i < board.length; i++) {
            for (int j = 0; j < board[i].length; j++) {
                if (board[i][j] == 1 || board[i][j] == 3) {
                    board[i][j] = 1;
                } else {
                    board[i][j] = 0;
                }
            }
        }
    }

    /*
    0：更新前后都是死细胞
    1：更新前后都是活细胞
    2：更新前是活细胞，更新后是死细胞
    3：更新前是死细胞，更新后是活细胞
    */

    // 按生存定律更新细胞状态
    private int updateStatus(int[][] board, int x, int y) {
        // 某个细胞周围活细胞数目 
        int livingCount = 0;
        for (int i = x - 1; i <= x + 1; i++) {
            for (int j = y - 1; j <= y + 1; j++) {
                if (i >= 0 && i < board.length && j >= 0 && j < board[0].length) {
                    if (board[i][j] == 1 || board[i][j] == 2) {
                        livingCount++;
                    }
                }
            }
        }
        // 减掉当前位置重复计算的值
        if (board[x][y] == 1 || board[x][y] == 2) {
            livingCount--;
        }
        if (board[x][y] == 1) {
            if (livingCount < 2 || livingCount > 3) {
                // 之前是活细胞，现在变成了死细胞
                return 2;
            } else {
                return 1;
            }
        } else {
            if (livingCount == 3) {
                // 之前是死细胞，现在变成了活细胞
                return 3;
            } else {
                return 0;
            }
        }
    }
}
```