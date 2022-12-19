![image.png](https://pic.leetcode-cn.com/b1a55af5b758d6b5a68d2809042e2000dcacf5dc782cb67bbd4ccc80354d1fa9-image.png)

```
    int[][] dir = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    boolean[][] flag;
    public int[][] floodFill(int[][] image, int sr, int sc, int newColor) {
        flag = new boolean[image.length][image[0].length];
        dfs(image, sr, sc, image[sr][sc], newColor);
        return image;
    }
    public void dfs(int[][] image, int sr, int sc, int oldColor, int newColor) {
        if(image[sr][sc] == oldColor && !flag[sr][sc]) {
            image[sr][sc] = newColor;
            flag[sr][sc] = true;
        } else {
            return;
        }
        int rl = image.length - 1;
        int cl = image[0].length - 1;
        for(int[] i : dir) {
            if(sr + i[0] > rl || sr + i[0] < 0 || sc + i[1] > cl || sc + i[1] < 0) {
                continue;
            }
            dfs(image, sr + i[0], sc + i[1], oldColor, newColor);
        }
    }
```
