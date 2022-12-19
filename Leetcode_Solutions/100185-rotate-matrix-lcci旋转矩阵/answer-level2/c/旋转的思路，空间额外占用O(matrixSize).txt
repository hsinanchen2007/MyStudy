### 解题思路
1、旋转最外圈
先临时存下第一行；
把第一列转上来到第一行；
把最下面一行转到第一列；
把最右边一列转到最下面一行；
把临时保存的原来第一行存入最右边一列；

2、缩小圈子重复第一步

### 代码

```c
void rotate(int** matrix, int matrixSize, int* matrixColSize){
    if (!matrix || matrixSize == 0 || !matrixColSize || matrixColSize[0] == 0) return;

    int temp[matrixSize];
    int left = 0;
    int right = matrixSize-1;

    while (left < right) {
        for (int i = 0; i < right - left + 1; i++) temp[i] = matrix[left][i+left];
        for (int i = 0; i < right - left + 1; i++) matrix[left][right-i] = matrix[i+left][left];
        for (int i = 0; i < right - left + 1; i++) matrix[i+left][left] = matrix[right][i+left];
        for (int i = 0; i < right - left + 1; i++) matrix[right][i+left] = matrix[right-i][right];
        for (int i = 0; i < right - left + 1; i++) matrix[i+left][right] = temp[i];

        left++;
        right--;
    }
}
```