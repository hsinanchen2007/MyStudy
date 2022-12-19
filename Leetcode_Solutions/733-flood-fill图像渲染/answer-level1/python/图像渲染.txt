####  方法：深度优先搜索
我们执行问题描述中的算法：从目标像素位置开始上色，渲染周边和目标像素初始颜色相同的像素。

**算法：**
- 将 `color` 置为目标像素初始颜色。我们从目标像素位置开始上色：若像素颜色和 `color` 相同则改变像素颜色为 `newColor`，然后再从四个方向进行上色，重复上述过程。
- 我们可以使用 `dfs` 函数对目标像素进行渲染。

```Python [ ]
class Solution(object):
    def floodFill(self, image, sr, sc, newColor):
        R, C = len(image), len(image[0])
        color = image[sr][sc]
        if color == newColor: return image
        def dfs(r, c):
            if image[r][c] == color:
                image[r][c] = newColor
                if r >= 1: dfs(r-1, c)
                if r+1 < R: dfs(r+1, c)
                if c >= 1: dfs(r, c-1)
                if c+1 < C: dfs(r, c+1)

        dfs(sr, sc)
        return image
```

```Java [ ]
class Solution {
    public int[][] floodFill(int[][] image, int sr, int sc, int newColor) {
        int color = image[sr][sc];
        if (color != newColor) dfs(image, sr, sc, color, newColor);
        return image;
    }
    public void dfs(int[][] image, int r, int c, int color, int newColor) {
        if (image[r][c] == color) {
            image[r][c] = newColor;
            if (r >= 1) dfs(image, r-1, c, color, newColor);
            if (c >= 1) dfs(image, r, c-1, color, newColor);
            if (r+1 < image.length) dfs(image, r+1, c, color, newColor);
            if (c+1 < image[0].length) dfs(image, r, c+1, color, newColor);
        }
    }
}

```

**复杂度分析**

* 时间复杂度：$O(N)$。$N$ 是图片像素的个数。我们可能渲染每一个像素。
* 空间复杂度：$O(N)$，调用 `dfs` 时隐式调用堆栈的大小。