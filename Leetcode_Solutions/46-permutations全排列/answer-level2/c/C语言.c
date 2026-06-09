### 解题思路
此处撰写解题思路

### 代码

```c
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

//函数一：计算序列结果大小
int calPermuteSize(int numsSize){
    int     i           = 0;
    int     iRetSize    = 1;

    for (i = 1; i <= numsSize; i++)
    {
        iRetSize *= i;
    }

    return iRetSize;
}

//函数二：回溯函数
void backTrackPermute(int* nums, int numsSize, int** pRet, int* pUsed, int* pRetPos, int iCurPos){
    int     i       = 0;
    int     iTmp    = 0;

    //1,结束条件
    if (iCurPos == numsSize)
    {
        *pRetPos += 1;
        memcpy(pRet[*pRetPos], pRet[(*pRetPos) - 1], sizeof(int) * numsSize);       //进行下一个结果的填写，将当前结果拷贝，否则前面的值为0
        return;
    }

    //2,回溯处理
    for (i = 0; i < numsSize; i++)
    {
        if (0 == pUsed[i])
        {
            iTmp = i;
            pRet[*pRetPos][iCurPos] = nums[i];
            pUsed[i] = 1;
            backTrackPermute(nums, numsSize, pRet, pUsed, pRetPos, iCurPos + 1);

            //3,回退处理
            pUsed[iTmp] = 0;
        }
    }

    return;
}

int** permute(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
    int         i           = 0;
    int         iRetSize    = 0;
    int**       pRet        = NULL;
    int*        pRetCol     = NULL;
    int*        pUsed       = NULL;
    int         iRetPos     = 0;

    //1,计算结果数量
    iRetSize = calPermuteSize(numsSize);

    //2,申请空间
    pRet = (int**)malloc(sizeof(int*) * (iRetSize + 1));
    pRetCol = (int*)malloc(sizeof(int) * (iRetSize + 1));
    pUsed = (int*)malloc(sizeof(int) * numsSize);
    memset(pUsed, 0x00, sizeof(int) * numsSize);

    for (i = 0; i <= iRetSize; i++)
    {
        pRet[i] = (int*)malloc(sizeof(int) * numsSize);
        memset(pRet[i], 0x00, sizeof(int) * numsSize);

        pRetCol[i] = numsSize;
    }

    //3,调用回溯函数
    backTrackPermute(nums, numsSize, pRet, pUsed, &iRetPos, 0);

    //4,释放空间
    free(pUsed);

    //5,返回
    *returnSize = iRetSize;
    *returnColumnSizes = pRetCol;
    return pRet;
}
```