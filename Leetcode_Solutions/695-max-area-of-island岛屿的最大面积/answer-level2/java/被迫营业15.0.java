class Solution {
private int result = 0;
private int curArea;

private void maxArea(int i1, int i2, int[][] grid) {
    if (i1 != -1 && i1 != grid.length && i2 != -1 && i2 != grid[0].length && grid[i1][i2] == 1) {
        grid[i1][i2] = ++curArea + 1;
        maxArea(i1 + 1, i2, grid);
        maxArea(i1 - 1, i2, grid);
        maxArea(i1, i2 + 1, grid);
        maxArea(i1, i2 - 1, grid);
    }
}

public int maxAreaOfIsland(int[][] grid) {
    for (int i1 = 0; i1 < grid.length; ++i1)
        for (int i2 = 0; i2 < grid[0].length; ++i2)
            if (grid[i1][i2] == 1) {
                curArea = 0;
                maxArea(i1, i2, grid);
                result = curArea > result ? curArea : result;
            }
    return result;
}
}