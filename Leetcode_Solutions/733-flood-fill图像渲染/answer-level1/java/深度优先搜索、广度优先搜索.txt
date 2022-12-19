bfs/dfs
```java
class Solution {

    public int[][] floodFill(int[][] image, int sr, int sc, int newColor) {
//        return bfs(image, sr, sc, newColor);
        dfs(image, sr, sc, newColor, image[sr][sc]);
        return image;
    }

    private int[][] bfs(int[][] image, int sr, int sc, int newColor) {
        Queue<int[]> queue = new ArrayDeque<>();
        int pixel = image[sr][sc];
        image[sr][sc] = -1;
        queue.add(new int[]{sr, sc});
        int[] pos;
        int x;
        int y;
        while (!queue.isEmpty()) {
            pos = queue.remove();
            x = pos[0];
            y = pos[1];

            if (x > 0 && image[x - 1][y] == pixel) {
                image[x - 1][y] = -1;
                queue.add(new int[]{x - 1, y});
            }
            if (x < image.length - 1 && image[x + 1][y] == pixel) {
                image[x + 1][y] = -1;
                queue.add(new int[]{x + 1, y});
            }
            if (y > 0 && image[x][y - 1] == pixel) {
                image[x][y - 1] = -1;
                queue.add(new int[]{x, y - 1});
            }
            if (y < image[0].length - 1 && image[x][y + 1] == pixel) {
                image[x][y + 1] = -1;
                queue.add(new int[]{x, y + 1});
            }
        }
        for (int i = 0; i < image.length; i++) {
            for (int j = 0; j < image[0].length; j++) {
                if (image[i][j] == -1) {
                    image[i][j] = newColor;
                }
            }
        }
        return image;
    }

    private void dfs(int[][] image, int x, int y, int newColor, int pixel) {
        if (x < 0 || x >= image.length || y < 0 || y >= image[0].length) {
            return;
        }
        if (image[x][y] != pixel || image[x][y] == newColor) {
            return;
        }
        image[x][y] = newColor;
        dfs(image, x - 1, y, newColor, pixel);
        dfs(image, x + 1, y, newColor, pixel);
        dfs(image, x , y-1, newColor, pixel);
        dfs(image, x, y + 1, newColor, pixel);

    }
    
}
```
