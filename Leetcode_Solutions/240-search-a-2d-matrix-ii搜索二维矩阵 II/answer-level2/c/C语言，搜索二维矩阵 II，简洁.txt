思路：缩小问题规模 (减治)
1. 设矩阵左下角元素 matrix[i][j] ，**它是第 i 行最小值，同时也是第 j 列最大值**
2. 若 target < matrix[i][j] (小于第 i 行最小值)，则排除第 i 行，令 i--
3. 若 target > matrix[i][j] (大于第 j 列最大值)，则排除第 j 列，令 j++
4. 循环 2~3 直到找到 target，或所有行列均被排除

代码：
```
bool searchMatrix(int** matrix, int matrixRowSize, int matrixColSize, int target) {
    int i = matrixRowSize - 1, j = 0;
    while (i >= 0 && j < matrixColSize) {
        if (target < matrix[i][j]) i--;
        else if (target > matrix[i][j]) j++;
        else return true;
    }
    return false;
}
```
