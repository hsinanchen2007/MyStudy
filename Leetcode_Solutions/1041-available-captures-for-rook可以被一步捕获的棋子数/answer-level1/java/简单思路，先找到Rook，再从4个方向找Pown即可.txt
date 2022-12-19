### 解题思路
两个步骤：
1、遍历找Rook
2、发散4个方向找p即可

其中有1个细节我觉得可以分享下：就是用一个循环完成4个方向查找：用一个二维数组表达4个方向
int[][] DIRECTIONS = new int[][]{{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

![image.png](https://pic.leetcode-cn.com/c9bd2c5e32edde54b85bbcf9dcca3700389b4bbd439c045e638f6da1b029989e-image.png)


### 代码

```java
public class Solution {
    private static final char BLANK = '.';
    private static final char ROOK_WHITE = 'R';
    private static final char ROOK_BLANK = 'r';
    private static final char POWN_WHITE = 'P';
    private static final char POWN_BLACK = 'p';
    private static final int[][] DIRECTIONS = new int[][]{{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    private static final int ROW_INDEX = 0;
    private static final int COL_INDEX = 1;

    public int numRookCaptures(char[][] board) {
        //找到rook的位置
        int[] rookPos = getRookPos(board);

        //统计4个方向上的数量
        int result = getAvailableEnemyPown(board, rookPos);

        return result;
    }

    private int[] getRookPos(char[][] board) {
        int[] rookPos = new int[2];

        //找R在哪儿
        for (int i = 0; i < board.length; i++) {
            for (int j = 0; j < board[i].length; j++) {
                if (board[i][j] == ROOK_WHITE || board[i][j] == ROOK_BLANK) {
                    rookPos[0] = i;
                    rookPos[1] = j;
                    break;
                }
            }
        }
        return rookPos;
    }

    private int getAvailableEnemyPown(char[][] board, int[] rookPos) {
        //确定敌方POWN
        char enemyPown = board[rookPos[ROW_INDEX]][rookPos[COL_INDEX]] == ROOK_WHITE ? POWN_BLACK : POWN_WHITE;

        int result = 0;

        for (int i = 0; i < DIRECTIONS.length; i++) {
            int row = rookPos[ROW_INDEX];
            int col = rookPos[COL_INDEX];
            int[] curDirection = DIRECTIONS[i];

            while (true) {
                row += curDirection[ROW_INDEX];
                col += curDirection[COL_INDEX];
                if (!isValid(row, col)) {
                    break;
                }
                if (board[row][col] != BLANK) {
                    if (board[row][col] == enemyPown) {
                        result++;
                    }
                    break;
                }
            }
        }
        return result;
    }

    private boolean isValid(int row, int col) {
        if (row > 7 || row < 0 || col > 7 || col < 0) {
            return false;
        }
        return true;
    }
}
```