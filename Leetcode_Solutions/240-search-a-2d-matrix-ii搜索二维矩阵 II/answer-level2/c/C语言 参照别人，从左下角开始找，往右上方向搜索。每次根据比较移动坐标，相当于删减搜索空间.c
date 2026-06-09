### 解题思路
此处撰写解题思路

### 代码

```c
bool searchMatrix(int** matrix, int matrixRowSize, int matrixColSize, int target) {
    if (matrixRowSize == 0 || matrixColSize == 0) {
        return false;
    }
    if (matrix[0][0] > target) {
        return false;
    }
    if (matrix[matrixRowSize - 1][matrixColSize - 1] < target) {
        return false;
    }
    int x = matrixRowSize - 1;
    int y = 0;
    while (x >= 0 && y < matrixColSize) {
        if (matrix[x][y] == target) {
            return true;
        } else if (matrix[x][y] > target) {
            x--;
        } else {
            y++;
        }
    }
    return false;

}
```