典型的dfs题目,不过要注意一个小问题,就是当前点的color值如果和newColor一样要跳过,不然会StackOverflowo(╥﹏╥)o
代码应该还可以优化一下
### 代码

```java
class Solution {
    private int [][]dir = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}};
    public int[][] floodFill(int[][] image, int sr, int sc, int newColor) {
        int ct = image[sr][sc];
        image[sr][sc] = newColor;
        for (int i = 0; i < 4; i++) {
            int nx = sr + dir[i][0];
            int ny = sc + dir[i][1];
            if(0 <= nx && nx < image.length && 0 <= ny && ny < image[0].length && image[nx][ny] == ct) {
                dfs(image, nx, ny, ct, newColor);
            }
        }
        return image;
    }

    private void dfs(int[][] image, int x, int y, int ct, int newColor) {
        if(image[x][y] == newColor) return;
        image[x][y] = newColor;
        for (int i = 0; i < 4; i++) {
            int nx = x + dir[i][0];
            int ny = y + dir[i][1];
            if(0 <= nx && nx < image.length && 0 <= ny && ny < image[0].length && image[nx][ny] == ct) {
                dfs(image, nx, ny, ct, newColor);
            }
        }
    }
}
```