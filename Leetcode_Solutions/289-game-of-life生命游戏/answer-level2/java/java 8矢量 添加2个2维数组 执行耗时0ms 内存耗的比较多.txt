### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public void gameOfLife(int[][] board) {
        int rowLength = board.length;
        int colLength = board[0].length;

        int[][] copyBord = new int[rowLength][colLength];

        for (int i = 0; i < rowLength; i++) {
            for (int j = 0; j < colLength; j++) {
                copyBord[i][j] = board[i][j];
            }
        }

        int[][] vectors = new int[][]{
                {-1, -1}, {-1, 0}, {-1, 1}, {0, -1},
                {0, 1},   {1, -1}, {1, 0},  {1, 1}};


        for (int i = 0; i < rowLength; i++) {
            for (int j = 0; j < colLength; j++) {
                int aroundSum = 0;

                for (int[] vector : vectors) {
                    int rowVector = vector[0];
                    int colVector = vector[1];

                    if (i + rowVector < 0
                            || i + rowVector >= rowLength) {
                        continue;
                    }
                    if (j + colVector < 0
                            || j + colVector >= colLength) {
                        continue;
                    }

                    aroundSum += board[i + rowVector][j + colVector];
                }

                // 活细胞
                if (board[i][j] == 1) {
                    copyBord[i][j] = aroundSum >= 2 && aroundSum <= 3 ? 1 : 0;
                } else {
                    // 死细胞
                    copyBord[i][j] = aroundSum == 3 ? 1 : 0;
                }
            }
        }

        for (int i = 0; i < rowLength; i++) {
            for (int j = 0; j < colLength; j++) {
                board[i][j] = copyBord[i][j];
            }
        }
    }
}
```