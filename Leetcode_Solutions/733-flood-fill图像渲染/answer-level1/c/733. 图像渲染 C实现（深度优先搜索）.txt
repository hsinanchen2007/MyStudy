### 解题思路
    注意初始坐标与新的颜色值相同的情况。

### 代码

```c
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
#define DIRECTION 4

void dfs(int** image, int imageSize, int imageColSize, int x, int y, int* dx, int* dy, int newColor, int oldColor)
{
    if (image[x][y] != oldColor) {
        return;
    }
    image[x][y] = newColor;
    for (int k = 0; k < DIRECTION; k++) {
        int nextX = x + dx[k];
        int nextY = y + dy[k];
        if (nextX < 0 || nextX >= imageSize || nextY < 0 || nextY >= imageColSize) {
            continue;
        }
        dfs(image, imageSize, imageColSize, nextX, nextY, dx, dy, newColor, oldColor);
    }
    return;
}

int** floodFill(int** image, int imageSize, int* imageColSize, int sr, int sc, int newColor, int* returnSize, int** returnColumnSizes){
    if (!image || imageSize <= 0) {
        *returnSize = 0;
        return NULL;
    }
    *returnSize = imageSize;
    *returnColumnSizes = (int*)malloc(sizeof(int) * imageSize);
    for (int i = 0; i < imageSize; i++) {
        (*returnColumnSizes)[i] = imageColSize[0];
    }
    if (image[sr][sc] == newColor) {
        return image;
    }
    int* dx = (int*)malloc(sizeof(int) * DIRECTION);
    dx[0] = 0; dx[1] = 0; dx[2] = -1; dx[3] = 1;
    int* dy = (int*)malloc(sizeof(int) * DIRECTION);
    dy[0] = 1; dy[1] = -1; dy[2] = 0; dy[3] = 0;
    dfs(image, imageSize, imageColSize[0], sr, sc, dx, dy, newColor, image[sr][sc]);
    free(dx);
    free(dy);
    return image;
}
```