### 解题思路
纯C 简单的流程控制
### 代码

```c
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
enum Direction
{
    up = 0,
    right,
    down,
    left,
};

int** generateMatrix(int n, int* returnSize, int** returnColumnSizes){
    if (n <= 0)
    {
        *returnSize = 0;
        *returnColumnSizes = (int*)malloc(1 * sizeof(int));
        (*returnColumnSizes)[*returnSize] = 0;
        return NULL;
    }

    enum Direction direction = 0; // LeetCode平台定义全局变量会报错，因此这里定义枚举类型
    int uiTop = 0;
    int uiRight = n - 1;
    int uiBottom = n - 1;
    int uiLeft = 0;

    int index = 0;
    int num = 0;

    int** ppRes = (int**)malloc(n * n * sizeof(int*));
    for (index = 0; index <= n - 1; index++)
    {
        ppRes[index] = (int*)malloc(n * sizeof(int));
    }

    *returnSize = n;
    *returnColumnSizes = (int*)malloc(n * sizeof(int));
    for (index = 0; index <= n - 1; index++)
    {
        (*returnColumnSizes)[index] = n;
    }

    while (num < n * n)
    {
        switch (direction)
        {   
            case up:
            {
                for (index = uiLeft; index <= uiRight; index++)
                {
                    ppRes[uiTop][index] = ++num;
                }

                uiTop++;
                break;
            }
            case right:
            {
                for (index = uiTop; index <= uiBottom; index++)
                {
                    ppRes[index][uiRight] = ++num;
                }

                uiRight--;
                break;
            }
            case down:
            {
                for (index = uiRight; index >= uiLeft; index--)
                {
                    ppRes[uiBottom][index] = ++num;
                }
                
                uiBottom--;
                break;
            }
            case left:
            {
                for (index = uiBottom; index >= uiTop; index--)
                {
                    ppRes[index][uiLeft] = ++num;
                }

                uiLeft++;
                break;
            }
            default:
                break;
        }

        direction = (++direction) % 4;
    }

    return ppRes;
}
```