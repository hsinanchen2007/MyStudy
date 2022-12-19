### 解题思路
方法一：回溯法
1，以选取的字符数 iCurPos 为索引，进行回溯
2，下一层选取数字的规则，只能选取剩下没有使用过的数字
3，结束条件，数字填完了
4，在上一题的基础上增加 判断是否是重复数字，避免除重
### 代码

```c
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */


//方法一：回溯法
//1，以选取的字符数 iCurPos 为索引，进行回溯
//2，下一层选取数字的规则，只能选取剩下没有使用过的数字
//3，结束条件，数字填完了

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

//函数三：判断是否是重复元素
bool checkRepeat(int** pRet, int* pRetPos, int iCurPos, int num){
    int     i       = 0;
    bool    bRet    = false;

    for (i = 0; i < *pRetPos; i++)
    {
        if ((0 == memcmp(&pRet[i][0], &pRet[*pRetPos][0], sizeof(int) * iCurPos)) && 
            (pRet[i][iCurPos] == num))
        {
            bRet = true;
            break;
        }
    }
    return bRet;
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
            //4,检查是否重复，避免除重
            if (checkRepeat(pRet, pRetPos, iCurPos, nums[i])) continue;
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

int** permuteUnique(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
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
    for (i = iRetPos; i <= iRetSize; i++)
    {
        free(pRet[i]);
    }

    //5,返回
    *returnSize = iRetPos;
    *returnColumnSizes = pRetCol;
    return pRet;
}
```