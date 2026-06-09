### 解题思路
此处撰写解题思路
（1）对角线置换
（2）收尾列一次置换

注意
对两个int x,y，交换算法：
(1)加法

```c
x = x + y;
y = x - y;
x = x - y;
```

(2)异或

```c
x = x ^ y;
y = x ^ y;
x = x ^ y;
```

### 代码

```c
void rotate(int** matrix, int matrixSize, int* matrixColSize){
    int i, j, m, row, col;
    
    if (matrix == NULL || matrixSize <= 1) {
        return;
    }

    row = matrixSize;
    col = *matrixColSize;

    /* 按照对角线进行转换数组元素 */
    for (i = 0; i < row; i++) {
        for (j = 0; j < i; j++) {
            matrix[i][j] = matrix[i][j] + matrix[j][i];
            matrix[j][i] = matrix[i][j] - matrix[j][i];
            matrix[i][j] = matrix[i][j] - matrix[j][i];
        }
    }

    /* 按照列进行数组元素转换 */
    for (i = 0, j = col - 1; i < j; i++, j--) {
        for (m = 0; m < row; m++) {
            matrix[m][i] = matrix[m][i] + matrix[m][j];
            matrix[m][j] = matrix[m][i] - matrix[m][j];
            matrix[m][i] = matrix[m][i] - matrix[m][j];
        }
    } 
}
```