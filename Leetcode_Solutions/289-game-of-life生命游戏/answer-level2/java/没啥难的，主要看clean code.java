### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
static final int LIVE = 1;
    static final int DEAD = 0;

    public void gameOfLife(int[][] board) {
        final int heightLength = board.length;
        final int widthLength = board[0].length;

        int[][] nextBoard = new int[heightLength][widthLength];
        for (int height = 0; height < heightLength; ++height) {
            for (int width = 0; width < widthLength; ++width) {
                int liveCount = getLiveCellCount(board, height, width);

                if (LIVE == board[height][width]) {
                    if (liveCount < 2) {
                        nextBoard[height][width] = DEAD;
                        continue;
                    }

                    if (liveCount == 2 || liveCount == 3) {
                        nextBoard[height][width] = LIVE;
                        continue;
                    }

                    if (liveCount > 3) {
                        nextBoard[height][width] = DEAD;
                    }

                } else {
                    if (liveCount == 3) {
                        nextBoard[height][width] = LIVE;
                    } else {
                        nextBoard[height][width] = DEAD;
                    }

                }


            }
        }


        for (int height = 0; height < heightLength; ++height) {
            for (int width = 0; width < widthLength; ++width) {
                board[height][width] = nextBoard[height][width];
            }

        }
    }

    public int getLiveCellCount(int[][] board, int height, int width) {
        int[] heightDirection = new int[]{0, 0, 1, -1, 1, -1, 1, -1};
        int[] widthDirection = new int[]{1, -1, 0, 0, 1, -1, -1, 1};

        final int heightLength = board.length;
        final int widthLength = board[0].length;

        int liveCount = 0;

        for (int direction = 0; direction < 8; direction++) {
            int newHeight = height + heightDirection[direction];
            int newWidth = width + widthDirection[direction];

            if (newHeight >= 0 && newHeight < heightLength &&
                    newWidth >= 0 && newWidth < widthLength) {
                if (board[newHeight][newWidth] == LIVE) {
                    ++liveCount;
                }
            }


        }

        return liveCount;

    }
}
```