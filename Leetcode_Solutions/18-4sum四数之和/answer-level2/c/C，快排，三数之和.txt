### 解题思路
1，快速排序，将输入数组正序排列
2，动态申请指针数据空间，保存返回数据数组指针
3，循环调用三数之和函数，三数之和函数做法见14题
4，去重

### 代码

```c
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int comp(const void *a, const void *b)
{
    return *(int *)a - *(int *)b;
}

int threeSum(int* nums, int numsSize, int target, int **pRetPoint)
{
    int     i       = 0;
    int     iLeft   = 0;
    int     iRight  = numsSize - 1;
    int     iBak_0  = -99;
    int     iBak_1  = -99;
    int     iBak_2  = -99;
    int     iRetSize = 0;
    int     iTmpSum = 0;

//    printf("numsSize=%d, target=%d\r\n", numsSize, target);

    for (i = 1; i < numsSize - 1; i++)
    {

        if (nums[i] != nums[i - 1])
        {
            //除重1：当中间元素和之前的元素相等时，iLeft 和 iRight 不能从头开始
            //避免产生相同结果的同时也能减少运行次数
            iLeft = 0;
            iRight = numsSize - 1;
        }

        while ((iLeft < i) && (iRight > i))
        {
//            if (nums[iLeft] > target)
//            {
//                //除重2： 左边小值大于target，则不可能凑出target，则直接退出
//                break;
//            }

            iTmpSum = nums[iLeft] + nums[i] + nums[iRight];
//            printf("iLeft=%d, i=%d, iRight=%d, target=%d,%d\r\n", iLeft, i, iRight, target, iTmpSum);

            if ((nums[iLeft] + nums[i] + nums[iRight]) < target)
            {
                //逻辑1：三个值小于target时，则左值 iLeft 右移，总值增加
                iLeft += 1;
            }
            else if ((nums[iLeft] + nums[i] + nums[iRight]) > target)
            {
                //逻辑2：三个值大于target时，则右值 iRight 左移，总值减小
                iRight -= 1;
            }
            else 
            {
                //逻辑3：三个值等于target时，记录结果，同时偏移 iLeft 右移，寻找下一个结果
                if (!((iBak_0 == nums[iLeft]) && (iBak_1 == nums[i]) && (iBak_2 == nums[iRight])))
                {
                    //除重3：将当前结果和前一个结果比较，只有不相同的才记录
                    pRetPoint[iRetSize] = malloc(sizeof(int) * 4);
                    pRetPoint[iRetSize][0] = nums[iLeft];
                    pRetPoint[iRetSize][1] = nums[i];
                    pRetPoint[iRetSize][2] = nums[iRight];
                    
                    iRetSize += 1;

                    iBak_0 = nums[iLeft];
                    iBak_1 = nums[i];
                    iBak_2 = nums[iRight];
//                    printf("iLeft=%d, i=%d, iRight=%d, num=%d\r\n", iLeft, i, iRight, iRetSize);
                }

                iLeft += 1;
            }
        }
    }

    return iRetSize;
}

//除重函数
int removeRepeat(int **pRetPoint, int retSize)
{
    int     i           = 0;
    int     j           = 0;
    int     iRetSize    = retSize;

    for (i = 0; i < iRetSize - 1; i++)
    {
        for (j = i + 1; j < iRetSize; j++)
        {
            if ((pRetPoint[i][0] == pRetPoint[j][0]) &&
                (pRetPoint[i][1] == pRetPoint[j][1]) &&
                (pRetPoint[i][2] == pRetPoint[j][2]) &&
                (pRetPoint[i][3] == pRetPoint[j][3]))
            {
                //两个答案重复，则删除一个
                free(pRetPoint[j]);
                memmove(&pRetPoint[j], &pRetPoint[j + 1], sizeof(char *) * (iRetSize - j - 1));
                iRetSize -= 1;
                j -= 1;
            }
        }
    }
    return iRetSize;
}

int** fourSum(int* nums, int numsSize, int target, int* returnSize, int** returnColumnSizes){
    int     **ppRet     = NULL;
    int     i           = 0;
    int     j           = 0;
    int     iRet        = 0;
    int     iRetSize    = 0;

    //1，快速排序
    qsort(nums, numsSize, sizeof(int), comp);

/*
    for (i = 0; i < numsSize; i++)
    {
        printf("%d, ", nums[i]);
    }
    printf("\n");
*/
    //2，申请指针数据空间
    ppRet = (int **)malloc(sizeof(int *) * (numsSize + 1) * 6);
    *returnColumnSizes = malloc(sizeof(int) * (numsSize + 1) * 6);

    //3，循环使用三数之和函数
    for (i = numsSize - 1; i >= 3; i--)
    {
        iRet = threeSum(nums, i, target - nums[i], &ppRet[iRetSize]);

//        printf("i=%d, num=%d, target=%d, iRet=%d \n", i, nums[i], target - nums[i], iRet);

        if (iRet > 0)
        {
            for (j = 0; j < iRet; j++)
            {
                ppRet[iRetSize + j][3] = nums[i];
                (*returnColumnSizes)[iRetSize + j] = 4;
            }
        }
        iRetSize += iRet;
    }

    //4，去重
    iRetSize = removeRepeat(ppRet, iRetSize);

    *returnSize = iRetSize;
    return ppRet;
}
















```