### 解题思路
1.其实很简单，就是按照题目，写出对应的判断条件
2.用一个等长的二维数组记下需要变换的位置，1-->0或者0-->1
3.代码很丑陋，介意勿看

### 代码

```java
class Solution {
    public int[][] gameOfLife(int[][] board) {
        //横向变换
        int[] row = {-1, 0, 1};
        //垂直变换
        int[] col = {-1, 0, 1};
        //等长数组，记录变换的位置
        int[][] changes = new int[board.length][board[0].length];
        for (int i = 0; i < board.length; i++) {
            for (int j = 0; j < board[i].length; j++) {
                checkChangeOrNot(board, changes, i, j, row, col);
            }
        }
        for (int i = 0; i < changes.length; i++) {
            for (int j = 0; j < changes[i].length; j++) {
                if (changes[i][j] == 1) {
                    if (board[i][j] == 0) {
                        board[i][j] = 1;
                    } else {
                        board[i][j] = 0;
                    }
                }
            }
        }
        return board;
    }

    private void checkChangeOrNot(int[][] board, int[][] changes, int i, int j, int[] row, int[] col) {
        int tempLive = 0;
        int tempDead = 0;
        for (int r : row) {
            for (int c : col) {
                //如果没变化，continue
                if (r == 0 && c == 0) {
                    continue;
                }
                //判断边界
                if (i + r >= 0 && i + r < board.length && j + c >= 0 && j + c < board[0].length) {
                    //重点：只能用周围的活细胞（1）来判断，因为超出边界不算
                    if (board[i][j] == 0 && board[i + r][j + c] == 1) {
                        ++tempLive;
                    }
                    if (board[i][j] == 1 && board[i + r][j + c] == 1) {
                        ++tempDead;
                    }
                }
            }
        }
        //判断条件就是题目
        if ((board[i][j] == 0 && tempLive == 3) || (board[i][j] == 1 && (tempDead < 2 || tempDead > 3))) {
            //需要翻转的坐标
            changes[i][j] = 1;
        }

    }
}
```