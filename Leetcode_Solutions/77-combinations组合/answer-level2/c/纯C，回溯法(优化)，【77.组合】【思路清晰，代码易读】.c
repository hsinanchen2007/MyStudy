### 解题思路
方法一：回溯法
1,结束条件，排列了K个数
2,回溯处理：下层节点只能使用上层节点未使用过的整数

优化一：回溯处理循环时减少循环次数(n - k + index + 1)


### 代码

```c
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

//方法一：回溯法
//1,结束条件，排列了K个数
//2,回溯处理：下层节点只能使用上层节点未使用过的整数

//优化一：回溯处理循环时减少循环次数(n - k + index + 1)

//函数一：求组合的数量
int getMaxComBineNum(int n, int k){
    int         iRet        = 0;
    int         i           = 0;
    long int    iTmp1       = 1;
    long int    iTmp2       = 1;

    for (i = 0; i < k; i++)
    {
        iTmp1 *= n - i;
        iTmp2 *= i + 1;
    }
    iRet = iTmp1 / iTmp2 + 1;
    return iRet;
}

//函数二：回溯函数
//1,val传入上一层的代入值，下一层只用后面的数字
//2,index 作为回溯函数下标，控制回溯层数
void backTrackCombine(int** pRet, int n, int k, int* pColSize, int* pRetNum, int val, int index){
    int     i       = 0;
    int     j       = 0;
    if (NULL == pRet[*pRetNum])
    {
        pRet[*pRetNum] = (int*)malloc(sizeof(int) * (k + 1));
        memset(pRet[*pRetNum], 0x00, sizeof(int) * (k + 1));
    }

    //1,结束条件
    if (index == k)
    {
        pColSize[*pRetNum] = k;
        *pRetNum += 1;
        pRet[*pRetNum] = (int*)malloc(sizeof(int) * (k + 1));
        memcpy(pRet[*pRetNum], pRet[(*pRetNum) - 1], sizeof(int) * (k + 1));
        return;
    }

    //2,回溯处理
    for (i = val + 1; i <= (n - k + index + 1); i++)
    {
        pRet[*pRetNum][index] = i;
        backTrackCombine(pRet, n, k, pColSize, pRetNum, i, index + 1);
    }

    return;
}

int** combine(int n, int k, int* returnSize, int** returnColumnSizes){
    int**       pRet        = NULL;
    int*        pColSize    = NULL;
    int         iMax        = 0;
    int         iRetNum     = 0;

    //1,计算组合数量，并初始化指针
    iMax = getMaxComBineNum(n, k);

    pRet = (int**)malloc(sizeof(int*) * iMax);
    memset(pRet, 0x00, sizeof(int*) * iMax);
    pColSize = (int*)malloc(sizeof(int) * iMax);
    memset(pColSize, 0x00, sizeof(int) * iMax);

    //2,回溯处理
    backTrackCombine(pRet, n, k, pColSize, &iRetNum, 0, 0);

    //3,返回
    *returnSize = iRetNum;
    *returnColumnSizes = pColSize;
    return pRet;
}
```