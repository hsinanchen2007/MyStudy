# 代码
```java
class Solution {
    private int[][] global_image;
    private int ori_color, new_color, global_row, global_col;

    public int[][] floodFill(int[][] image, int sr, int sc, int newColor) {
        global_row = image.length;
        global_col = image[0].length;
        if (image[sr][sc] == newColor) return image;
        ori_color = image[sr][sc];
        new_color = newColor;
        global_image = image;
        dfs(sr, sc);
        return image;
    }

    private void dfs(int row, int col) {
        global_image[row][col] = new_color;
        if (row > 0 && global_image[row - 1][col] == ori_color)
            dfs(row - 1, col);
        if (col > 0 && global_image[row][col - 1] == ori_color)
            dfs(row, col - 1);
        if (row + 1 < global_row && global_image[row + 1][col] == ori_color)
            dfs(row + 1, col);
        if (col + 1 < global_col && global_image[row][col + 1] == ori_color)
            dfs(row, col + 1);
    }
}
```
