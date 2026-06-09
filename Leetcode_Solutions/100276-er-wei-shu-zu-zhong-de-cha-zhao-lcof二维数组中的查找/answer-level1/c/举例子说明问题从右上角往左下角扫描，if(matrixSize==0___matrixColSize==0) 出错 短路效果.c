### 解题思路
此处撰写解题思路

### 代码

```c


bool findNumberIn2DArray(int** matrix, int matrixSize, int* matrixColSize, int target){
    #if 1
    if((matrixSize == 0) || ((*matrixColSize == 0)))
    {
        return false;
    }
    #endif
    #if 0
    if(*matrixColSize==0||matrixSize==0)
         return false;
    #endif
    int row = 0;
    int col = *matrixColSize - 1;
    bool flag = false;

    while((row < matrixSize) && (col >= 0))
    {
        if(matrix[row][col] == target)
        {
            flag = true;
            break;
        }
        else if(matrix[row][col] > target)
        {
            col--;
        }
        else
        {
            row++;
        }
    }

    return flag;
}


```