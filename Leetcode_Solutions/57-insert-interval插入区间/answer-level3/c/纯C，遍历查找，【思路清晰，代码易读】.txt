### 解题思路
方法一：遍历查找
1,循环遍历区间列表，将和新区间无关的区间直接添加到返回列表中
2,在循环过程中找到新区间的头位置，尾位置，并且在返回列表中预留空间
3,将新区间或者合并后的空间插入 返回列表中预留的空间

### 代码

```c
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

//方法一：遍历查找
//1,循环遍历区间列表，将和新区间无关的区间直接添加到返回列表中
//2,在循环过程中找到新区间的头位置，尾位置，并且在返回列表中预留空间
//3,将新区间或者合并后的空间插入 返回列表中预留的空间

#define     MIN(a, b)   ((a) < (b) ? (a) : (b))
#define     MAX(a, b)   ((a) > (b) ? (a) : (b))

int** insert(int** intervals, int intervalsSize, int* intervalsColSize, int* newInterval, int newIntervalSize, int* returnSize, int** returnColumnSizes){
    int     i           = 0;
    int     iRetSize    = 0;            //返回区间的个数
    int     iInsert     = 0;            //插入区间的位置
    bool    bFlag       = false;        //是否找到插入位置的标记
    bool    bHFlag      = false;        //是否找到头位置的标记
    int     iHpos       = 0;            //头位置
    int     iTpos       = 0;            //尾位置
    int**   pRet        = NULL;
    int*    pColSize    = NULL;

    //1,初始化
    pRet = (int**)malloc(sizeof(int*) * (intervalsSize + 1));
    memset(pRet, 0x00, sizeof(int*) * (intervalsSize + 1));
    pColSize = (int*)malloc(sizeof(int) * (intervalsSize + 1));
    memset(pColSize, 0x00, sizeof(int) * (intervalsSize + 1));

    //2,循环遍历区间集合，找到插入新区间的头尾
    for (i = 0; i < intervalsSize; i++)
    {
        if (intervals[i][1] < newInterval[0])
        {
            //如果新区间在当前区间的后面，则将当前区间填入返回空间
            pRet[iRetSize] = (int*)malloc(sizeof(int) * 2);
            pRet[iRetSize][0] = intervals[i][0];
            pRet[iRetSize][1] = intervals[i][1];
            pColSize[iRetSize] = 2;
            iRetSize += 1;
            continue;
        }
        else
        {
            if (!bHFlag)
            {
                //第一次区间尾大于新区间的头，则找到了新区间的头位置
                bHFlag = true;
                iHpos = i;
            }
            if (!bFlag)
            {
                //在返回空间中预留一个位置给新区间
                bFlag = true;
                iInsert = iRetSize;
                iRetSize += 1;
            }
        }

        if (intervals[i][0] > newInterval[1])
        {
            //如果新区间在当前区间的前面，则将当前区间填入返回空间时
            pRet[iRetSize] = (int*)malloc(sizeof(int) * 2);
            pRet[iRetSize][0] = intervals[i][0];
            pRet[iRetSize][1] = intervals[i][1];
            pColSize[iRetSize] = 2;
            iRetSize += 1;
        }
        else
        {
            //如果新区间的尾在当前区间的后面，则尾位置往后移
            iTpos = i;
        }
    }

    if (!bFlag)
    {
        //如果一次遍历没有找到新区间插入的位置，说明新区间在所有区间的后面
        bFlag = true;
        iInsert = iRetSize;
        iRetSize += 1;
    }

    //3,插入新区间
    pRet[iInsert] = (int*)malloc(sizeof(int) * 2);
    pColSize[iInsert] = 2;
    if (iRetSize > intervalsSize)
    {
        //如果已经插入到返回集合中的区间个数大于原来区间个数，说明新区间是个单独的区间，直接插入即可
        pRet[iInsert][0] = newInterval[0];
        pRet[iInsert][1] = newInterval[1];
    }
    else 
    {
        //说明新区间和原集合中的区间产生了重叠，需要合并区间
        pRet[iInsert][0] = MIN(intervals[iHpos][0], newInterval[0]);
        pRet[iInsert][1] = MAX(intervals[iTpos][1], newInterval[1]);
    }

    //4,返回
    *returnSize = iRetSize;
    *returnColumnSizes = pColSize;
    return pRet;
}
```