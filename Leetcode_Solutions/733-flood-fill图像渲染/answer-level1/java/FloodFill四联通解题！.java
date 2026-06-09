### 解题思路
![屏幕快照 2020-02-06 14.23.54.png](https://pic.leetcode-cn.com/c2ee2bc95b0f50e03cfae436db780df13efa4902cbd9ec3c205751d91dd376fc-%E5%B1%8F%E5%B9%95%E5%BF%AB%E7%85%A7%202020-02-06%2014.23.54.png)


### 代码

```java
class Solution {

    /**
     * 寻路方向四方向
     */
    private static int[][] d = new int[][]{{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    /**
     * 访问标记
     */
    private static boolean[][] visited;
    /**
     * 寻路矩阵尺寸
     */
    private static int m, n;

    public int[][] floodFill(int[][] image, int sr, int sc, int newColor) {
        m = image.length;
        n = image[0].length;
        visited = new boolean[m][n];
        dfs(image, sr, sc, newColor);
        return image;
    }

    private void dfs(int[][] image, int sr, int sc, int newColor) {
        visited[sr][sc] = true;
        int oldColor = image[sr][sc];
        if (oldColor == newColor) {
            return;
        }
        image[sr][sc] = newColor;
        for (int i = 0; i < d.length; i++) {
            int nex = sr + d[i][0];
            int ney = sc + d[i][1];
            if (inArea(nex,ney) && !visited[nex][ney] && image[nex][ney] == oldColor) {
                floodFill(image, nex, ney, newColor);
            }
        }
    }

    private static boolean inArea(int x, int y) {
        return x >= 0 && x < m && y >= 0 && y < n;
    }
}
```