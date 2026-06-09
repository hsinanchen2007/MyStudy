### 解题思路
//对撞指针模型算法：
1, 快速排序,将原有数组排序
2，对撞指针逻辑执行
3，除重

### 代码

```c
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int comp(const void *a,const void *b)
{
    return *(int *)a - *(int *)b;
}

//对撞指针模型算法：
int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
    int     **ppRet      = NULL;
    int     **ppCSize    = NULL;

    int     i       = 0;
    int     iLeft   = 0;
    int     iRight  = numsSize - 1;
    int     s       = 0;

    int     iBak_0  = -1;
    int     iBak_1  = -1;
    int     iBak_2  = -1;

    *returnSize = 0;
    if (numsSize == 0)
    {
        return NULL;
    }

    //快速排序：注意qsort的用法 comp 为自定义的比较函数，两个元素的大小由自己控制
    qsort(nums, numsSize, sizeof(int), comp);

    ppRet = (int **)malloc(sizeof(int *) * (numsSize + 1) * 6);     // 理解为 创建一个 int* 指针 数组，每个指针还需要 malloc 3个int大小保存结果
    *returnColumnSizes = malloc(sizeof(int) * (numsSize + 1) * 6);  // 理解为 创建一个 int 数组，每个数组保存3，每个数组的大小

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
            if (nums[iLeft] > 0)
            {
                //除重2： 左边小值大于0，则不可能凑出0值，则直接退出
                break;
            }
            
            if ((nums[iLeft] + nums[i] + nums[iRight]) < 0)
            {
                //逻辑1：三个值小于0时，则左值 iLeft 右移，总值增加
                iLeft += 1;
            }
            else if ((nums[iLeft] + nums[i] + nums[iRight]) > 0)
            {
                //逻辑2：三个值大于0时，则右值 iRight 左移，总值减小
                iRight -= 1;
            }
            else 
            {
                //逻辑3：三个值等于0时，记录结果，同时偏移 iLeft 右移，寻找下一个结果
                if (!((iBak_0 == nums[iLeft]) && (iBak_1 == nums[i]) && (iBak_2 == nums[iRight])))
                {
                    //除重3：将当前结果和前一个结果比较，只有不相同的才记录
                    ppRet[*returnSize] = malloc(sizeof(int) * 3);
                    ppRet[*returnSize][0] = nums[iLeft];
                    ppRet[*returnSize][1] = nums[i];
                    ppRet[*returnSize][2] = nums[iRight];
                    (*returnColumnSizes)[*returnSize] = 3;
                    
                    *returnSize += 1;

                    iBak_0 = nums[iLeft];
                    iBak_1 = nums[i];
                    iBak_2 = nums[iRight];
//                    printf("iLeft=%d, i=%d, iRight=%d, num=%d\r\n", iLeft, i, iRight, *returnSize);
                }

                iLeft += 1;
            }
        }
    }

    return ppRet;
}


/*
// 暴力破解法，超时
int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
    int     **ppRet      = NULL;
    int     **ppCSize    = NULL;

    int     i       = 0;
    int     j       = 0;
    int     k       = 0;
    int     s       = 0;

    *returnSize = 0;
    if (numsSize == 0)
    {
        return NULL;
    }

    qsort(nums, numsSize, sizeof(int), comp);
    ppRet = (int **)malloc(sizeof(int *) * (numsSize + 1) * 6);     // 理解为 创建一个 int* 指针 数组，每个指针还需要 malloc 3个int大小保存结果
    *returnColumnSizes = malloc(sizeof(int) * (numsSize + 1) * 6);  // 理解为 创建一个 int 数组，每个数组保存3，每个数组的大小

    for (i = 0; i < numsSize - 2; i++)
    {
        for (j = i + 1; j < numsSize -1; j++)
        {
            for (k = j + 1; k < numsSize; k++)
            {
                if (nums[i] + nums[j] + nums[k] == 0)
                {
                    for (s = 0; s < *returnSize; s++)
                    {
                        if ((nums[i] == ppRet[s][0]) && (nums[j] == ppRet[s][1]) && (nums[k] == ppRet[s][2]))
                        {
                            break;
                        }
                    }

                    if (s >= *returnSize)
                    {
                        ppRet[*returnSize] = malloc(sizeof(int) * 3);
                        ppRet[*returnSize][0] = nums[i];
                        ppRet[*returnSize][1] = nums[j];
                        ppRet[*returnSize][2] = nums[k];
                        (*returnColumnSizes)[*returnSize] = 3;

                        (*returnSize) += 1;
                        printf("i=%d, j=%d, k=%d, num=%d\r\n", i, j, k, *returnSize);
                    }
                }
            }
        }
    }

    return ppRet;
}
*/

```