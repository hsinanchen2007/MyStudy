```
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
void changeValue(int** image, int imageSize, int* imageColSize, int sr, int sc, int newColor, int** res, bool** flag, int* returnSize, int** returnColumnSizes) {
    res[sr][sc] = newColor;
    if (sr > 0 && image[sr - 1][sc] == image[sr][sc] && !flag[sr - 1][sc])  {
        flag[sr - 1][sc] = true;
        changeValue(image, imageSize, imageColSize, sr - 1, sc, newColor, res, flag, returnSize, returnColumnSizes);
    }
    if (sc > 0 && image[sr][sc - 1] == image[sr][sc] && !flag[sr][sc - 1])  {
        flag[sr][sc - 1] = true;
        changeValue(image, imageSize, imageColSize, sr, sc - 1, newColor, res, flag, returnSize, returnColumnSizes);
    }
    if (sr < imageSize - 1 && image[sr + 1][sc] == image[sr][sc] && !flag[sr + 1][sc])  {
        flag[sr + 1][sc] = true;
        changeValue(image, imageSize, imageColSize, sr + 1, sc, newColor, res, flag, returnSize, returnColumnSizes);
    }
    if (sc < imageColSize[sr] - 1 && image[sr][sc + 1] == image[sr][sc] && !flag[sr][sc + 1])  {
        flag[sr][sc + 1] = true;
        changeValue(image, imageSize, imageColSize, sr, sc + 1, newColor, res, flag, returnSize, returnColumnSizes);
    }
}

int** floodFill(int** image, int imageSize, int* imageColSize, int sr, int sc, int newColor, int* returnSize, int** returnColumnSizes){
    int** res = malloc(sizeof(int*) * imageSize);
    bool** flag = malloc(sizeof(bool*) * imageSize);
    *returnSize = imageSize;
    *returnColumnSizes = malloc(sizeof(int) * imageSize);
    for (int i = 0; i < imageSize; i++) {
        res[i] = malloc(sizeof(int) * imageColSize[i]);
        flag[i] = malloc(sizeof(bool) * imageColSize[i]);
        memset(res[i], 0, sizeof(int) * imageColSize[i]);
        memset(flag[i], 0, sizeof(bool) * imageColSize[i]);
        (*returnColumnSizes)[i] = imageColSize[i];
    }
    flag[sr][sc] = true;
    changeValue(image, imageSize, imageColSize, sr, sc, newColor, res, flag, returnSize, returnColumnSizes);
    for (int i = 0; i < imageSize; i++) {
        for (int j = 0; j < imageColSize[i]; j++) {
            if (flag[i][j] == false) res[i][j] = image[i][j];
        }
        free(flag[i]);
    }
    free(flag);
    return res;
}
```
