### 解题思路
和之前的岛屿数量问题很像

### 代码

```java
class Solution {
    public int[][] floodFill(int[][] image, int sr, int sc, int newColor) {
        if (image[sr][sc] == newColor) {
            return image;
        }
        fill(image, sr, sc, image[sr][sc], newColor);
        return image;
    }
    
    public void fill(int[][] image, int sr, int sc, int color, int newColor) {
        if (sr >= image.length || sr < 0 || sc >= image[0].length || sc < 0 || image[sr][sc] != color) {
            return;
        }
        image[sr][sc] = newColor;
        fill(image, sr - 1, sc, color, newColor);
        fill(image, sr + 1, sc, color, newColor);
        fill(image, sr, sc - 1, color, newColor);
        fill(image, sr, sc + 1, color, newColor);
    }
}
```