### 解题思路
纯C 深度优先 递归算法框架
整天碰到回溯题，没有C语言版本的，自己总结一个

### 代码

```c
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
/* 定义返回二维数组的行数 */
#define MAX_SIZE 600
/* 标明输入、输出参数 */
#define PARAM_IN 
#define PARAM_OUT 

static void dfs(PARAM_IN int* candidates, PARAM_IN int candidatesSize, PARAM_IN int target,
                PARAM_OUT int* returnSize, PARAM_OUT int** returnColumnSizes, 
                PARAM_OUT int** ppRes, PARAM_IN int* pBuffer, PARAM_IN int indexOfCan, PARAM_IN int indexOfBuf)
{
    int index = 0;

    if (0 == target)
    {  
        // 存入新值，更新返回数组
        ppRes[*returnSize] = (int*)malloc(indexOfBuf * sizeof(int));
        memcpy(ppRes[*returnSize], pBuffer, indexOfBuf * sizeof(int));
        (*returnColumnSizes)[*returnSize] = indexOfBuf;
        (*returnSize)++;
    }
    else if (0 < target)
    {
        for (index = indexOfCan; index <= candidatesSize - 1; index++)
        {
            if (indexOfCan != index && candidates[index - 1] == candidates[index]) // 若index为indexOfCan，必执行一次，类似do while
            {
                continue;
            }

            pBuffer[indexOfBuf] = candidates[index]; // 更新缓存

            dfs(candidates, candidatesSize, target - candidates[index], // 更新target
                 returnSize, returnColumnSizes,                               
                 ppRes, pBuffer, index, indexOfBuf + 1); // index作为indexOfCan传入，indexOfBuf加1
            // 退出后indexOfBuf回到原先值
        }
    }
}

int** combinationSum(PARAM_IN int* candidates, PARAM_IN int candidatesSize, PARAM_IN int target, 
                     PARAM_OUT int* returnSize, PARAM_OUT int** returnColumnSizes)
{
    int indexOfCan = 0;
    int indexOfBuf = 0;

    int** ppRes = (int**)malloc(MAX_SIZE * sizeof(int*)); // 返回数组
    int* pBuffer = (int*)malloc(target * sizeof(int)); // 缓存

    *returnSize = 0;
    *returnColumnSizes = (int*)malloc(MAX_SIZE * sizeof(int)); // 初始化输出参数

    dfs(candidates, candidatesSize, target,    
        returnSize, returnColumnSizes,         
        ppRes, pBuffer, indexOfCan, indexOfBuf);
    
    return ppRes;
}
```