### 解题思路
构造一维数组记录高度

### 代码

```c
// 调用84题
static int LargestRectangleArea(int* pHeights, int heightsSize)
{
    int max = 0;
    int tmp = 0;
    int slow = 0;
    int fast = 0;
    int minheight = 0;

    for (slow = 0; slow <= heightsSize - 1; slow++)
    {
        minheight = pHeights[slow];

        for (fast = slow; fast <= heightsSize - 1; fast++)
        {
            minheight = pHeights[fast] < minheight ? pHeights[fast] : minheight;
            tmp = minheight * (fast - slow + 1);
            max = tmp > max ? tmp : max;
        }
    }

    return max;
}

int maximalRectangle(char** matrix, int matrixSize, int* matrixColSize){
    if (0 == matrixSize)
    {
        return 0;
    }

    int* pHeight = (int*)malloc(*matrixColSize * sizeof(int));
    memset(pHeight, 0, *matrixColSize * sizeof(int));
    int row = 0; 
    int col = 0;
    int max = 0;
    int tmp = 0;

    for (row = 0; row <= matrixSize - 1; row++)
    {
        for (col = 0; col <= *matrixColSize - 1; col++)
        {
            if (matrix[row][col] == '1')
            {
                pHeight[col]++;
            }
            else if (matrix[row][col] == '0')
            {
                pHeight[col] = 0;
            }
        }

        tmp = LargestRectangleArea(pHeight, *matrixColSize);
        max = tmp > max ? tmp : max;
    }

    return max;
}


```