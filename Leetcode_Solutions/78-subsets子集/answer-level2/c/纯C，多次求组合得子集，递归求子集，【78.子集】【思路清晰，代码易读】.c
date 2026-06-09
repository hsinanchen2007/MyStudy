### 解题思路
方法一：利用77题组合的方法求子集
1,将 77题中 1-n 中求 k 个数的组合，修改为 n 个正数数组中求 k 个数的组合
2,子集就是求出 k= 0-n 的所有组合

方法二：递归法
1, 递归法需要找出 f(n) 和 f(n-1) 的关系
2, [1,2] 的子集是[][1][2][1,2], 而[1,2,3] 的子集是[][1][2][1,2][3][1,3][2,3][1,2,3]
3, f(n) = f(n-1) + (f(n-1) 的每个子集加上 n)

### 代码

```c
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

//方法二：递归法
//1, 递归法需要找出 f(n) 和 f(n-1) 的关系
//2, [1,2] 的子集是[][1][2][1,2], 而[1,2,3] 的子集是[][1][2][1,2][3][1,3][2,3][1,2,3]
//3, f(n) = f(n-1) + (f(n-1) 的每个子集加上 n)

//函数一：递归函数
void recusiveSubSets(int* nums, int n, int** pRet, int* pColSize, int* pRetNum){
    int     i       = 0;
    int     iTmpNum = 0;
    //1,结束条件
    if(n == 0)
    {
        pRet[*pRetNum] = (int*)malloc(sizeof(int) * 0);
        pColSize[*pRetNum] = 0;
        *pRetNum += 1;
        return;
    }

    //2,递归调用
    recusiveSubSets(nums, n - 1, pRet, pColSize, pRetNum);

    //3,f(n)结果处理
    iTmpNum = (*pRetNum);
    for(i = 0; i < iTmpNum; i++)
    {
        pRet[*pRetNum] = (int*)malloc(sizeof(int) * (pColSize[i] + 1));
        memcpy(pRet[*pRetNum], pRet[i], sizeof(int) * pColSize[i]);
        pRet[*pRetNum][pColSize[i]] = nums[n - 1];

        pColSize[*pRetNum] = pColSize[i] + 1;
        *pRetNum += 1;
    }
    return;
}

int** subsets(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
    int         iMax        = 10000;
    int         iRetNum     = 0;
    int**       pRet        = NULL;
    int*        pColSize    = NULL;

    //1,初始化
    pRet = (int**)malloc(sizeof(int*) * iMax);
    memset(pRet, 0x00, sizeof(int*) * iMax);
    pColSize = (int*)malloc(sizeof(int) * iMax);
    memset(pColSize, 0x00, sizeof(int) * iMax);

    //2,递归调用
    recusiveSubSets(nums, numsSize, pRet, pColSize, &iRetNum);

    //3,返回
    *returnSize = iRetNum;
    *returnColumnSizes = pColSize;
    return pRet;
}



/*
//方法一：利用77题组合的方法求子集
//1,将 77题中 1-n 中求 k 个数的组合，修改为 n 个正数数组中求 k 个数的组合
//2,子集就是求出 k= 0-n 的所有组合

//函数一：回溯法求 n 个正数数组中 k 个数的组合
void backTrackCombine(int* nums, int n, int k, int** pRet, int* pRetNum, int* pColSize, int val, int index){
    int     i       = 0;
    //1, k=0时特殊处理
    if (k == 0)
    {
        pRet[*pRetNum] = (int*)malloc(sizeof(int) * k);
        pColSize[*pRetNum] = k;
        *pRetNum += 1;
        return;
    }

    if (pRet[*pRetNum] == NULL)
    {
        pRet[*pRetNum] = (int*)malloc(sizeof(int) * (k));
    }

    //2,结束条件
    if (index == k)
    {
        pColSize[*pRetNum] = k;
        *pRetNum += 1;
        pRet[*pRetNum] = (int*)malloc(sizeof(int) * (k + 1));
        memcpy(pRet[*pRetNum], pRet[(*pRetNum) - 1], sizeof(int) * k);
        return;
    }

    //3,回溯法
    for (i = val; i <= (n - k + index); i++)
    {
        pRet[*pRetNum][index] = nums[i];
        backTrackCombine(nums, n, k, pRet, pRetNum, pColSize, i + 1, index + 1);
    }

    return;
}

int** subsets(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
    int         i           = 0;
    int         iMax        = 10000;
    int         iRetNum     = 0;
    int**       pRet        = NULL;
    int*        pColSize    = NULL;

    pRet = (int**)malloc(sizeof(int*) * iMax);
    memset(pRet, 0x00, sizeof(int*) * iMax);
    pColSize = (int*)malloc(sizeof(int) * iMax);
    memset(pColSize, 0x00, sizeof(int) * iMax);

    for(i = 0; i <= numsSize; i++)
    {
        backTrackCombine(nums, numsSize, i, pRet, &iRetNum, pColSize, 0, 0);
    }

    *returnSize = iRetNum;
    *returnColumnSizes = pColSize;
    return pRet;
}
*/
```