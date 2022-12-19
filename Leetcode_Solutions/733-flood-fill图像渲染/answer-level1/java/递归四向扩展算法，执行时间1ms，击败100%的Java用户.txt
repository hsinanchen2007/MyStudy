执行用时 :1 ms, 在所有 Java 提交中击败了100.00%的用户
内存消耗 :45.1 MB, 在所有 Java 提交中击败了74.27%的用户

不多解释，代码一眼就能看懂。

```
class Solution {
    public int[][] floodFill(int[][] image, int sr, int sc, int newColor) {
        int oldColor = image[sr][sc];
        if (oldColor == newColor) return image;
        image[sr][sc] = newColor;
        if ((sr > 0) && (image[sr - 1][sc] == oldColor)) floodFill(image, sr - 1, sc, newColor);
        if ((sr < image.length - 1) && (image[sr + 1][sc] ==oldColor)) floodFill(image, sr + 1, sc, newColor);
        if ((sc > 0) && (image[sr][sc - 1] == oldColor)) floodFill(image, sr, sc - 1, newColor);
        if ((sc < image[0].length - 1) && (image[sr][sc + 1] ==oldColor)) floodFill(image, sr, sc + 1, newColor);
        return image;
    }
}
```
