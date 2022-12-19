### 解题思路
1、对角线翻转
2、轴对称翻转
![image.png](https://pic.leetcode-cn.com/112a5ade65939e6adeab0c3295833ab47691496f6a4a7b450b524cab5ff29f27-image.png)

### 代码

```c
void rotate(int** matrix, int matrixSize, int* matrixColSize){
    int row = 0;
    int col = 0;
    int tmp = 0;

    // 对角线翻转
    for (row = 0; row <= matrixSize - 1; row++)
    {
        for (col = row + 1; col <= *matrixColSize - 1; col++)
        {
            tmp = matrix[row][col];
            matrix[row][col] = matrix[col][row];
            matrix[col][row] = tmp;
        }
    }

    // 轴对称翻转
    for (row = 0; row <= matrixSize - 1; row++)
    {
        for (col = 0; col <= (*matrixColSize - 1) / 2; col++)
        {
            tmp = matrix[row][col];
            matrix[row][col] = matrix[row][*matrixColSize - 1 - col];
            matrix[row][*matrixColSize - 1 - col] = tmp;
        }
    }
}
```