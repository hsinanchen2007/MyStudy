### 解题思路
![屏幕快照 2020-03-01 21.57.33.png](https://pic.leetcode-cn.com/b36ff83d0856096bb62d06463dd2cfcdcc77427a9d535a49d19bd75b10bb1d5b-%E5%B1%8F%E5%B9%95%E5%BF%AB%E7%85%A7%202020-03-01%2021.57.33.png)


### 代码

```java
class Solution {

    /**
     * 寻路方向四方向
     */
    private static int[][] d = new int[][]{{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    /**
     * 寻路矩阵尺寸
     */
    private static int m, n;
    /**
     * 访问标记
     */
    private static boolean[][] visited;

    public int[][] floodFill(int[][] image, int sr, int sc, int newColor) {
        m = image.length;
        n = image[0].length;
        visited = new boolean[m][n];
        dfs(image, sr, sc, newColor);
        return image;
    }

    private void dfs(int[][] image, int startx, int starty, int newColor) {
        visited[startx][starty] = true;
        for (int i = 0; i < d.length; i++) {
            int nex = startx + d[i][0];
            int ney = starty + d[i][1];
            if (inArea(nex, ney) && !visited[nex][ney] && image[nex][ney] == image[startx][starty]) {
                dfs(image, nex, ney, newColor);
            }
        }
        image[startx][starty] = newColor;
    }

    private static boolean inArea(int x, int y) {
        return x >= 0 && x < m && y >= 0 && y < n;
    }
}
```