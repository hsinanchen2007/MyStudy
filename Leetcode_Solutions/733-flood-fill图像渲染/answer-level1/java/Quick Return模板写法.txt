### 解题思路
模板写法
1. 传入的新color必须和起始点color不同
2. 上下左右四个方向进行dfs
3. dfs结束条件是超出坐标范围 或者 和起始颜色不同

### 代码

```java
class Solution {
    public int[][] floodFill(int[][] image, int sr, int sc, int newColor) {
        int color = image[sr][sc];
        if (color != newColor) {
            dfs(image, sr, sc, color, newColor);
        }
        return image;
    }

    private void dfs(int[][] image, int sr, int sc, int color, int newColor) {
        if (sr >= image.length || sc >= image[0].length || sr < 0 || sc < 0) {
            return;
        }
        if(image[sr][sc]!=color){
            return;
        }
        image[sr][sc] = newColor;
        dfs(image, sr + 1, sc, color, newColor);
        dfs(image, sr, sc + 1, color, newColor);
        dfs(image, sr - 1, sc, color, newColor);
        dfs(image, sr, sc - 1, color, newColor);
        
    }
}
```