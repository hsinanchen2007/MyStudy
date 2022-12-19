### 解题思路
两次二分法

### 代码

```c
bool searchMatrix(int** matrix, int matrixSize, int* matrixColSize, int target){
    if (0 == matrixSize || 0 == *matrixColSize)
    {
        return false;
    }

    // 先找出第几行
    int lowRow = 0;
    int highRow = matrixSize - 1;
    int midRow = 0;

    int highCol = *matrixColSize - 1;
    int targetRow = -1;

    while (lowRow + 1 < highRow)
    {
        midRow = lowRow + (highRow - lowRow) / 2;

        if (matrix[midRow][highCol] == target)
        {
            return true;
        }

        if (matrix[midRow][highCol] < target)
        {
            lowRow = midRow;
        }
        else if (target < matrix[midRow][highCol])
        {
            highRow = midRow;
        }
    }

    if (matrix[lowRow][highCol] >= target)
    {
        targetRow = lowRow;
    }
    else if (matrix[highRow][highCol] >= target)
    {
        targetRow = highRow;
    }
    else
    {
        return false;
    }

    // 再找到第几列
    int low = 0;
    int high = *matrixColSize - 1;
    int mid = 0;

    while (low + 1 < high)
    {
        mid = low + (high - low) / 2;
        if (matrix[targetRow][mid] == target)
        {
            return true;
        }
        if (matrix[targetRow][mid] < target)
        {
            low = mid;
        }
        else if (target < matrix[targetRow][mid])
        {
            high = mid;
        }
    }

    if (matrix[targetRow][low] == target || matrix[targetRow][high] == target)
    {
        return true;
    }
    else
    {
        return false;
    }
}
```