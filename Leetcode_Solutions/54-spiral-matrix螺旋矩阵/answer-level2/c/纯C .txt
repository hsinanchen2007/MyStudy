### 解题思路
纯C 简单的流程控制

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
enum Direction
{
    up = 0,
    right,
    down,
    left,
};

int* spiralOrder(int** matrix, int matrixSize, int* matrixColSize, int* returnSize){
    if (NULL == matrix || 0 == matrixSize || 0 == *matrixColSize)
    {
        *returnSize = 0;
        return NULL;
    }

    enum Direction direction = 0; // LeetCode平台定义全局变量会报错，因此这里定义枚举类型
    int uiTop = 0;
    int uiRight = *matrixColSize - 1;
    int uiBottom = matrixSize - 1;
    int uiLeft = 0;

    int index = 0;
    *returnSize = 0;

    int* pRes = (int*)malloc(matrixSize * (*matrixColSize) * sizeof(int));

    while (uiTop <= uiBottom && uiLeft <= uiRight)
    {
        switch (direction)
        {   
            case up:
            {
                for (index = uiLeft; index <= uiRight; index++)
                {
                    pRes[(*returnSize)++] = matrix[uiTop][index];
                }

                uiTop++;
                break;
            }
            case right:
            {
                for (index = uiTop; index <= uiBottom; index++)
                {
                    pRes[(*returnSize)++] = matrix[index][uiRight];
                }

                uiRight--;
                break;
            }
            case down:
            {
                for (index = uiRight; index >= uiLeft; index--)
                {
                    pRes[(*returnSize)++] = matrix[uiBottom][index];
                }
                
                uiBottom--;
                break;
            }
            case left:
            {
                for (index = uiBottom; index >= uiTop; index--)
                {
                    pRes[(*returnSize)++] = matrix[index][uiLeft];
                }

                uiLeft++;
                break;
            }
            default:
                break;
        }

        direction = (++direction) % 4;
    }

    return pRes;
}
```