这个方法，从中心点，按照上右下左的顺序依次对相邻格子，进行检查。
检查过的，四个方向都是同一个颜色，则在markBorder数组中会被置为1.
下次再重复检查到此处，如果不等于0，代表检查过了，跳过。避免死循环
检查下来，不是同一颜色，那么代表边界，在markBorder数组中会被置为2.
图示：
0  -1 -1 -1 -1  0
-1  2  2  2  2 -1
-1  2  1  1  2 -1
-1  2  2  2  2 -1
0  -1 -1 -1 -1  0
边界就是 数字 2 那一圈。题目所求
数字 1 的是内界
数字 -1 代表外界
这个算法并不够好，会遍历循环所有内界和边界，应该能优化很多东西。


```
public int[][] colorBorder(int[][] grid, int r0, int c0, int color) {
            int width = grid.length;
            if (width == 0) return grid;
            int height = grid[0].length;
            if (height == 0) return grid;
            int[][] markBorder = new int[width][height];
            check4Direction(grid, r0, c0, markBorder);

            //paint
            for (int i = 0; i < markBorder.length; i++) {
                for (int j = 0; j < markBorder[i].length; j++) {
                    int mark = markBorder[i][j];
                    if (mark == 2) grid[i][j] = color;
                }
            }
            return grid;
        }

        /**
         * the beside block: 
         * if different color the beside block is -1 && this block is 2 as border.
         * the same color : this block is 1;
         * and 
         * check the border of grid at first
         */
        private void check4Direction(int[][] grid, int r, int c, int[][] markBorder) {
            if (r >= markBorder.length || r < 0) return;
            if (c >= markBorder[r].length || c < 0) return;
            if (markBorder[r][c] == 0) {
                if (r == 0 || r == markBorder.length - 1) {
                    markBorder[r][c] = 2;
                }
                if (c == 0 || c == markBorder[r].length - 1) {
                    markBorder[r][c] = 2;
                }
            } else return;
            boolean isBorder = false;
            if (r > 0)
                if (grid[r - 1][c] != grid[r][c]) {
                    markBorder[r - 1][c] = -1;
                    isBorder = true;
                }
            if (r < markBorder.length - 1)
                if (grid[r + 1][c] != grid[r][c]) {
                    markBorder[r + 1][c] = -1;
                    isBorder = true;
                }
            if (c < markBorder[0].length - 1)
                if (grid[r][c + 1] != grid[r][c]) {
                    markBorder[r][c + 1] = -1;
                    isBorder = true;
                }
            if (c > 0)
                if (grid[r][c - 1] != grid[r][c]) {
                    markBorder[r][c - 1] = -1;
                    isBorder = true;
                }
            if (isBorder)
                markBorder[r][c] = 2;
            else
                markBorder[r][c] = Math.max(1, markBorder[r][c]);
            check4Direction(grid, r - 1, c, markBorder);
            check4Direction(grid, r, c + 1, markBorder);
            check4Direction(grid, r + 1, c, markBorder);
            check4Direction(grid, r, c - 1, markBorder);
        }
```
