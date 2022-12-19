输入：grid = [[1,1,1],[1,0,1],[1,1,1]]
输出：9

如果能满足题意,则四条边必定满足**四条边分别在grid的和**==**四条边分别的坐标边长**.

![IMG_20190928_214519.jpg](https://pic.leetcode-cn.com/4075822738a842f7793464aa3dde2b4dbfc09638c75bf0a610a59eaa913e60a9-IMG_20190928_214519.jpg)

```
    class Solution {
        public int largest1BorderedSquare(int[][] grid) {
            int height = grid.length;
            int wide = grid[0].length;
            int[][] colSum = new int[height + 1][wide + 1];
            int[][] rowSum = new int[height + 1][wide + 1];
            for (int i = 1; i <= height; i++) {
                for (int j = 1; j <= wide; j++) {
                    if (grid[i - 1][j - 1] == 0) {
                        rowSum[i][j] = 0;
                    } else {
                        rowSum[i][j] = rowSum[i][j - 1] + 1;
                    }
                }
            }
            for (int i = 1; i <= wide; i++) {
                for (int j = 1; j <= height; j++) {
                    if (grid[j - 1][i - 1] == 0) {
                        colSum[j][i] = 0;
                    } else {
                        colSum[j][i] = colSum[j - 1][i] + 1;
                    }
                }
            }
            int area = 0;
            for (int x1 = 0; x1 < wide; x1++) {
                for (int y1 = 0; y1 < height; y1++) {
                    if (grid[y1][x1] == 0) {
                        continue;
                    }
                    for (int x2 = x1,y2 = y1; x2 < wide && y2 < height; x2++,y2++) {
                            if (grid[y2][x2] == 0) {
                                continue;
                            }
                            if (isRectangle(y1 + 1, x1 + 1, y2 + 1, x2 + 1, colSum, rowSum)) {
                                if (y1 == y2 || x1 == x2) {
                                    area = Integer.max(1, area);
                                } else {
                                    if ((y2 - y1) == (x2 - x1 )){
                                        area = Integer.max((y2 - y1 + 1) * (x2 - x1 + 1), area);
                                    }

                                }

                            }

                    }

                }
            }
            return area;
        }

        private boolean isRectangle(int y1, int x1, int y2, int x2, int[][] colSum, int[][] rowSum) {
            return y2 - y1 == colSum[y2][x1] - colSum[y1][x1] &&
                    y2 - y1 == colSum[y2][x2] - colSum[y1][x2] &&
                    x2 - x1 == rowSum[y1][x2] - rowSum[y1][x1] &&
                    x2 - x1 == rowSum[y2][x2] - rowSum[y2][x1] ;
        }
    }
```
