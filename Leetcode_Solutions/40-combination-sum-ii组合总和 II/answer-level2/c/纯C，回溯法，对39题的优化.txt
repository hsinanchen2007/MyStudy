### 解题思路
和39题解的区别：
1,该题有重复元素，但是每个数字在组合中只能使用一次
2,在分支处理时使用 index+1 调用处理下一轮，则解决了每个数字在组合中只能使用一次的问题
3,保存当前节点数据时判断当前值是否已经回溯处理过，处理过则跳过，解决了重复元素导致结果重复的问题，避免了查重
4,优化了细节，1）在剪枝返回时，将当前保存值置0，2）在找到正确值，拷贝到下一轮时准确处理，已确保3判断正确，

### 代码

```c
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
//和39题解的区别：
//1,该题有重复元素，但是每个数字在组合中只能使用一次
//2,在分支处理时使用 index+1 调用处理下一轮，则解决了每个数字在组合中只能使用一次的问题
//3,保存当前节点数据时判断当前值是否已经回溯处理过，处理过则跳过，解决了重复元素导致结果重复的问题，避免了查重
//4,优化了细节，1）在剪枝返回时，将当前保存值置0，2）在找到正确值，拷贝到下一轮时准确处理，已确保3判断正确，

//回溯函数
//pRet          保存结果数组指针
//pRetSize      答案组数指针
//pRetCol       保存每组答案大小的数组指针
//iRetPos       当前答案的当前位置，作为回溯函数的控制变量
//index         输入数据的当前下标
int backTrackCombination(int* candidates, int candidatesSize, int target, int** pRet, int* pRetSize, int* pRetCol, int iRetPos, int index){
    int     i       = 0;
    int     iTmp    = 0;

    //1,结束条件
    if (target == 0)   return 0;        //target == 0   表示找到正确结果，保存结果后剪枝
    if (target < 0)    return -1;       //target < 0    表示该分支不成立，可以剪枝

    //2,回溯处理
    for (i = index; i < candidatesSize; i++)
    {
        //保存当前节点数据，区别2，增加判断解决重复元素导致结果重复的问题
//        printf("[1] i=%d, pRetSize=%d, iRetPos=%d, val=%d-%d, target=%d\n", i, *pRetSize, iRetPos, pRet[*pRetSize][iRetPos], candidates[i], target);
        if (pRet[*pRetSize][iRetPos] == candidates[i])
        {
            continue;
        }

        pRet[*pRetSize][iRetPos] = candidates[i];

        //分支处理，区别1，i+1处理下一分支，解决每个数字只能使用一次的问题
        iTmp = backTrackCombination(candidates, candidatesSize, target - candidates[i], pRet, pRetSize, pRetCol, iRetPos + 1, i + 1);
    
        //剪枝处理
        if (iTmp == 0)
        {
//            printf("[2] i=%d, pRetSize=%d, iRetPos=%d, val=%d-%d, target=%d\n", i, *pRetSize, iRetPos, pRet[*pRetSize][iRetPos], candidates[i], target);
            //该结果正确，保存结果
            pRetCol[*pRetSize] = iRetPos + 1;
            memcpy(pRet[*pRetSize + 1], pRet[*pRetSize], sizeof(int) * (iRetPos));      //优化1，确保if判断正确性
            *pRetSize += 1;

            //剪枝:返回上一层
            return 1;
        }

        if (iTmp < 0)
        {
//            printf("[3] i=%d, pRetSize=%d, iRetPos=%d, val=%d, target=%d\n", i, *pRetSize, iRetPos, candidates[i], target);
            //剪枝:返回上一层
            pRet[*pRetSize][iRetPos] = 0;       //优化2，确保if判断正确性
            return 1;
        }
    }
    pRet[*pRetSize][iRetPos] = 0;               //优化3，确保if判断正确性
    return 1;
}

//去重函数
void removeRepeat(int** pRet, int* pRetSize, int* pRetCol){
    int     i           = 0;
    int     iTmpSize    = 0;

    return 0;
}

//快速排序比较方法
int compare(const void* a, const void* b){
    return *(int*)a - *(int*)b;
}

//方法一：回溯法
//1,以target为目标，依次填入数组中元素，画出树形图，总结回溯条件
//2,每一个节点，数组中的元素都需要尝试
//3,当前节点的 target < 0 则该分支无效，直接剪枝，返回到上一层，进行下一个分支处理
//4,当前节点的 target == 0 则保存当前结果，然后剪枝，返回到上一层，进行下一个分支处理
//5,当前节点的 target > 0 则target - candidates[i] ; iRetPos + 1  进行下一层
//优化：
//当前进入下一层时，从数组中当前位置带入元素，可以避免结果中产生相同的结果，就避免了除重的处理
int** combinationSum2(int* candidates, int candidatesSize, int target, int* returnSize, int** returnColumnSizes){

    int         i           = 0;
    int**       pRet        = NULL;
    int*        pRetCol     = NULL;
    int         iRetSize    = 0;
    int         iDefSize    = 200;

    //1,初始化
    pRet = (int**)malloc(sizeof(int*) * iDefSize);   
    pRetCol = (int*)malloc(sizeof(int) * iDefSize);
    memset(pRetCol, 0x00, sizeof(int) * iDefSize);

    for (i = 0; i < iDefSize; i++)
    {
        pRet[i] = (int*)malloc(sizeof(int) * iDefSize);
        memset(pRet[i], 0x00, sizeof(int) * iDefSize);
    }

    //2,将输入数组排序
    qsort(candidates, candidatesSize, sizeof(int), compare);

    //3,调用回溯函数
    backTrackCombination(candidates, candidatesSize, target, pRet, &iRetSize, pRetCol, 0, 0);

    //4,去重
//    removeRepeat(pRet, &iRetSize, pRetCol);

    //5,释放多余空间
    for (i = iRetSize; i < iDefSize; i++)
    {
        free(pRet[i]);
    }

    //6,返回
    *returnSize = iRetSize;
    *returnColumnSizes = pRetCol;
    return pRet;
}
```