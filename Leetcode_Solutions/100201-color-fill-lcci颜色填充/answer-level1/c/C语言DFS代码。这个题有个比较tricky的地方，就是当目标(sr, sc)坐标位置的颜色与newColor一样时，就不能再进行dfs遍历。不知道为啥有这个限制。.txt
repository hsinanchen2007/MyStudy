C语言DFS代码。这个题有个比较tricky的地方，就是当目标(sr, sc)坐标位置的颜色与newColor一样时，就不能再进行dfs遍历。不知道为啥有这个限制。

```
#define DIRECTIONS 4
#define COORDINATE_DIM 2
int directions[DIRECTIONS][COORDINATE_DIM] = {
    {1, 0}, {0,  1}, {-1, 0}, {0, -1}
};

void dfs(int** image, int row, int col, int x, int y, int newColor, int targetColor)
{
    // out of boundary.
    if ((x < 0) || (x >= row) || (y < 0) || (y >= col)) {
        return;
    }

    // no target color.
    if (image[x][y] != targetColor) {
        return;
    }

    // update new color.
    image[x][y] = newColor;

    // dfs recursive other nodes.
    for (int i = 0; i < DIRECTIONS; i++) {
        dfs(image, row, col, x + directions[i][0], y + directions[i][1], newColor, targetColor);
    }
}

int** floodFill(int** image, int imageSize, int* imageColSize, int sr, int sc, int newColor, int* returnSize, int** returnColumnSizes){

    *returnSize = 0;
    if ((imageSize <= 0) || (imageColSize[0] <= 0)) {
        return NULL;
    }

    int targetColor = image[sr][sc];

    if (targetColor != newColor) {
        // dfs recursive loop.
        dfs(image, imageSize, imageColSize[0], sr, sc, newColor, targetColor);
    }

    // assemble results.
    *returnSize = imageSize;
    returnColumnSizes[0] = (int*)malloc(sizeof(int) * imageSize);
    for (int i = 0; i < imageSize; i++) {
        returnColumnSizes[0][i] = imageColSize[0];
    }

    return image;
}
```
![image.png](https://pic.leetcode-cn.com/7c36542f4e33f909c5794f23ff3f42fd1de6c599fda5ae3ca57346e045232c12-image.png)
