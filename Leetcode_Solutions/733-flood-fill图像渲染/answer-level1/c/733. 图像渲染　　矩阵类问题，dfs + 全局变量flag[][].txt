### 解题思路
有一幅以二维整数数组表示的图画，每一个整数表示该图画的像素值大小，数值在 0 到 65535 之间。

给你一个坐标 (sr, sc) 表示图像渲染开始的像素值（行 ，列）和一个新的颜色值 newColor，让你重新上色这幅图像。

为了完成上色工作，从初始坐标开始，记录初始坐标的上下左右四个方向上像素值与初始坐标相同的相连像素点，接着再记录这四个方向上符合条件的像素点与他们对应四个方向上像素值与初始坐标相同的相连像素点，……，重复该过程。将所有有记录的像素点的颜色值改为新的颜色值。

最后返回经过上色渲染后的图像。

示例 1:

输入: 
image = [[1,1,1],[1,1,0],[1,0,1]]
sr = 1, sc = 1, newColor = 2
输出: [[2,2,2],[2,2,0],[2,0,1]]
解析: 
在图像的正中间，(坐标(sr,sc)=(1,1)),
在路径上所有符合条件的像素点的颜色都被更改成2。
注意，右下角的像素没有更改为2，
因为它不是在上下左右四个方向上与初始点相连的像素点。


### 代码

```c
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

int arr[100][100] = {0};

int** dfs(int **image, int imageSize, int imageColSize, int sr, int sc, int newColor, int sourceColor){

    if (sr < 0 || sr >= imageSize || sc < 0 || sc >=imageColSize || arr[sr][sc] ==1) 
        return image;
    arr[sr][sc] = 1;
    if (image[sr][sc] == sourceColor){
        image[sr][sc] = newColor;
        dfs(image, imageSize, imageColSize, sr - 1, sc, newColor, sourceColor);
        dfs(image, imageSize, imageColSize, sr + 1, sc, newColor, sourceColor);
        dfs(image, imageSize, imageColSize, sr, sc - 1, newColor, sourceColor);
        dfs(image, imageSize, imageColSize, sr, sc + 1, newColor, sourceColor);
    }

    return image;
}

int** floodFill(int** image, int imageSize, int* imageColSize, int sr, int sc, int newColor, int* returnSize, int** returnColumnSizes){
    int i = 0;

    memset(arr, 0, 10000*sizeof(int));
    *returnSize = imageSize;
    *returnColumnSizes = malloc(imageColSize[0] * sizeof(int));
    for (i = 0; i < imageSize; i++)
        (*returnColumnSizes)[i] = imageColSize[0];
    //printf("%d %d\n",sc, sc, image[sr][sc])

    return dfs(image, imageSize, imageColSize[0], sr, sc, newColor, image[sr][sc]);
}
```