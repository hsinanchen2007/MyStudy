![}MG8UBFN{~K4C\]M})L(O4@A.png](https://pic.leetcode-cn.com/232e0df6dc18de532c1a8f0fe87931fbf86a6560853d7eab937b61758d2a2fb8-%7DMG8UBFN%7B~K4C%5DM%7D\)L\(O4@A.png)
一开始想很长时间,没想到暴力DFS就是结果...
加上一点优化速度提高了四倍
![QVFK2RJTE0U82EYGG}Q`BEE.png](https://pic.leetcode-cn.com/192815846f3b2d2306ffc978f763339ac86319ebf205e004634b471db0e443c2-QVFK2RJTE0U82EYGG%7DQ%60BEE.png)
```
    static class Solution {
        int height;
        int wide;
        int res = 0;
        int[][] grid;

        public int getMaximumGold(int[][] grid) {
            this.grid = grid;
            height = grid.length;
            wide = grid[0].length;
            for (int i = 0; i < height; i++) {
                for (int j = 0; j < wide; j++) {
                    if (grid[i][j] != 0 && TP(i, j) >= 3) {
                        boolean[][] b = new boolean[height][wide];
                        DFS(i, j, 0, b);
                    }
                }
            }
            return res;
        }

        private void DFS(int y, int x, int sum, boolean[][] isUsed) {
            /**
             * 特判,"撞墙"直接返回结果
             */
            if (y >= height || x >= wide || y < 0 || x < 0 || isUsed[y][x] || grid[y][x] == 0) {
                res = Integer.max(res, sum);
                return;
            }
            isUsed[y][x] = true;
            DFS(y + 1, x, sum + grid[y][x], isUsed);
            DFS(y, x + 1, sum + grid[y][x], isUsed);
            DFS(y - 1, x, sum + grid[y][x], isUsed);
            DFS(y, x - 1, sum + grid[y][x], isUsed);
            isUsed[y][x] = false;
        }

        /**
         * 特判,由于起点必定在路径的两端 而不是在路径里面,
         * 所以只要一个点四个路径有两个数字大于0,他就是这个路径里面的点.
         * 四个角需要特殊处理,因为[[23,21],[23,3]] 按以上方法处理后结果为0
         */
        private int TP(int y, int x) {
            if (y == 0 && x == 0 ||
                    y == 0 && x == wide - 1 ||
                    y == height - 1 && x == 0 ||
                    y == height - 1 && x == wide - 1) {
                return 3;
            }
            int r = 0;
            if (y - 1 < 0 || grid[y - 1][x] == 0) {
                r++;
            }
            if (y + 1 >= height || grid[y + 1][x] == 0) {
                r++;
            }
            if (x - 1 < 0 || grid[y][x - 1] == 0) {
                r++;
            }
            if (x + 1 >= wide || grid[y][x + 1] == 0) {
                r++;
            }
            return r;
        }
    }
```
