### 解题思路
此处撰写解题思路

### 代码

```c
bool findNumberIn2DArray(int** matrix, int matrixSize, int* matrixColSize, int target){
    int row = 0;
    int column = *matrixColSize-1;
    if (matrixSize == 0)
    {
        return false;
    }
    while((column >= 0) && (row < matrixSize))
    {
        if (target > matrix[row][column])
        {
            row++;
        }
        else if (target < matrix[row][column])
        {
            column--;
        }
        else
        {
            return true;
        }

    }
    return false;
}
```