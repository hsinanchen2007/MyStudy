### 解题思路
分治法：
1,  将集合分为两半，分治处理左支和右支
2,  最后合并左右支
3,  边界条件，集合中只有一个区间，或者两个区间直接合并

问题：
1,  左支和右支的区间分别处理之后，分支两边的区间还有重叠的区间
2,  合并两个分支的区间也是一个复杂的问题，并不比问题本身简单

解决问题：
1,一次合并两个分支很难得到最终解,那么尽可能合并一次之后再重新做一次分治处理,直到集合数量不在发生变化
2,由此引入了递归的想法

递归
1,将分治法得到的新区间集合再做一次分治算法
2,结束条件，分治算法得到的结果一致不再变化

### 代码

```c
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
//方法一：递归+分治算法

//分治法：
//1,将集合分为两半，分治处理左支和右支
//2,最后合并左右支
//3,边界条件，集合中只有一个区间，或者两个区间直接合并

//问题：
//1,左支和右支的区间分别处理之后，分支两边的区间还有重叠的区间
//2,合并两个分支的区间也是一个复杂的问题，并不比问题本身简单

//解决问题：
//1,一次合并两个分支很难得到最终解,那么尽可能合并一次之后再重新做一次分治处理,直到集合数量不在发生变化
//2,由此引入了递归的想法

//递归
//1,将分治法得到的新区间集合再做一次分治算法
//2,结束条件，分治算法得到的结果一致不再变化，

#define     MIN(a, b)   ((a) < (b) ? (a) : (b))
#define     MAX(a, b)   ((a) > (b) ? (a) : (b))
#define     INVALID     0xffff

//函数一：合并左右分支中的区间,想直接得到最终解复杂程度并不比原题简单
//将右支能合并到左支的区间都合并到左支，原右支的区间设置成无效区间
void mergeTwoIntervals(int** pLeft, int iLnum, int** pRight, int iRnum){
    int     i       = 0;
    int     j       = 0;

    for (i = 0; i < iLnum; i++)
    {
        for (j = 0; j < iRnum; j++)
        {
            if ((pLeft[i][1] >= pRight[j][0]) && 
                    (pLeft[i][0] <= pRight[j][1]))
            {
                pLeft[i][0] = MIN(pLeft[i][0], pRight[j][0]);
                pLeft[i][1] = MAX(pLeft[i][1], pRight[j][1]);
                pRight[j][0] = INVALID;
                pRight[j][1] = INVALID;
            }
        }
    }

    return;
}

//函数二：整理集合，将集合中由于合并产生的无效区间[INVALID, INVALID]用后面有效的区间替换
int arrangeIntervals(int** intervals, int intervalsSize){
    int     i       = 0;
    int     j       = intervalsSize - 1;
    int     iRet    = intervalsSize;

    for (i = 0; i <= j; i++)
    {
        if ((intervals[i][0] == INVALID) && (intervals[i][1] == INVALID))
        {
            iRet -= 1;
            for (; j > i; j--)
            {
                if ((intervals[j][0] != INVALID) || intervals[j][1] != INVALID)
                {
                    intervals[i][0] = intervals[j][0];
                    intervals[i][1] = intervals[j][1];
                    intervals[j][0] = INVALID;
                    intervals[j][1] = INVALID;
                    j -= 1;
                    break;
                }
                iRet -= 1;
            }
        }
    }
    return iRet;
}

//函数三：分治算法
int divideMerge(int** intervals, int intervalsSize){
    int     iLeftNum        = 0;
    int     iRightNum       = 0;

    //1,结束条件
    if (intervalsSize == 1)
    {
        return 1;
    }
    if (intervalsSize == 2)
    {
        if ((intervals[0][1] >= intervals[1][0]) && 
            (intervals[0][0] <= intervals[1][1]))
        {
            intervals[0][0] = MIN(intervals[0][0], intervals[1][0]);
            intervals[0][1] = MAX(intervals[0][1], intervals[1][1]);
            intervals[1][0] = INVALID;
            intervals[1][1] = INVALID;
            return 1;
        }
        return 2;
    }

    //2,左右支处理
    iLeftNum = divideMerge(&intervals[0], intervalsSize / 2);
    iRightNum = divideMerge(&intervals[intervalsSize / 2], (intervalsSize + 1) / 2);
    
    //3,左右支融合，经过左右支处理后，再找出左支和右支中能够合并的区间
    mergeTwoIntervals(&intervals[0], iLeftNum, &intervals[intervalsSize / 2], iRightNum);

    //4,整理集合,将集合中的无效区间去除
    return arrangeIntervals(intervals, intervalsSize);
}

//函数四：递归调用
//左右支区间融合，并不能得到最终解，通过递归分治来处理
//结束条件，当调用分治算法函数之后区间集合数目没有发生变化
int recursiveMerge(int** intervals, int intervalsSize){
    int     iTmpSize    = 0;
    //1,结束条件
    iTmpSize = divideMerge(intervals, intervalsSize);

    if (iTmpSize == intervalsSize)
    {
        return iTmpSize;
    }

    //递归调用
    return recursiveMerge(intervals, iTmpSize);
}

//主函数
int** merge(int** intervals, int intervalsSize, int* intervalsColSize, int* returnSize, int** returnColumnSizes){
    int         i           = 0;
    int**       pRet        = NULL;
    int*        pColSize    = NULL;
    int         iRetSize    = 0;

    if ((NULL == intervals) || (0 == intervalsSize))
    {
        *returnSize = 0;
        return NULL;
    }

    //1,初始化
    pRet = (int**)malloc(sizeof(int*) * intervalsSize);
    memset(pRet, 0x00, sizeof(int*) * intervalsSize);
    pColSize = (int*)malloc(sizeof(int) * intervalsSize);
    memset(pColSize, 0x00, sizeof(int) * intervalsSize);

    //2,递归调用
    iRetSize = recursiveMerge(intervals, intervalsSize);

    //3,赋值结果
    for (i = 0; i < iRetSize; i++)
    {
        pRet[i] = (int*)malloc(sizeof(int) * 2);
        memcpy(pRet[i], intervals[i], sizeof(int) *2);
        pColSize[i] = 2;
    }

    //4,返回
    *returnSize = iRetSize;
    *returnColumnSizes = pColSize;
    return pRet;
}
```