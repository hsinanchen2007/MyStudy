### 解题思路

![image.png](https://pic.leetcode-cn.com/cd8abf61bf75f2e1ac4d85c699bd28e12eb415319e27a1af3456513195e591fa-image.png)
外层循环次数应该可以不用sqrt求对角线长度，可能用时还能短一些吧

### 代码

```c
void rotate(int** matrix, int matrixSize, int* matrixColSize){
    int row, col, diagonal;
    int i ,j;
    int tmp;

    row = matrixSize;
    col = *matrixColSize;
    diagonal = sqrt(row * row + col * col) * 0.5 + 0.5;

    // 沿对角线
    // x => col-1-y
    // y => x
    // 替换4次为一圈, 回到 (x,y)
    for (i = 0; i < diagonal; i++)
    {
        for(j = i; j < col-i-1; j++)
        {
            tmp = matrix[i][j];
            // (i,j) = (col-1-j, i)
            matrix[i][j] = matrix[col - j - 1][i];
            // (col-1-j, i) = (col-1-i, col-1-j)
            matrix[col - j - 1][i] = matrix[col - i - 1][col - j - 1];
            // (col-1-i, col-1-j) = (col-1-(col-1-j), col-1-i) = (j, col-1-i)
            matrix[col - i - 1][col - j - 1] = matrix[j][col - i - 1];
            // (j, col-1-i) = (col-1-(col-1-i), j) = (i,j) = tmp
            matrix[j][col - i - 1] = tmp;
        }
    }
}
```