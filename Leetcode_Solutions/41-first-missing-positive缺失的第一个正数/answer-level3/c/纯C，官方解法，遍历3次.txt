### 解题思路
方法二：官方解法
    1,查找是否有1，没有则直接返回1
    2,将小于1，或者大于 numsSize 的数字全部修改为1
    3,遍历修改后的数组，用数字作为下标，将数组对应位置的元素修改符号
    4,遍历数组，找到第一个正数，下标即为没有出现的最小正整数

### 代码

```c
#define     ABS(a)      ((a) < 0) ? (-a) : (a)  

//方法二：官方解法
//1,查找是否有1，没有则直接返回1
//2,将小于1，或者大于 numsSize 的数字全部修改为1
//3,遍历修改后的数组，用数字作为下标，将数组对应位置的元素修改符号
//4,遍历数组，找到第一个正数，下标即为没有出现的最小正整数
int firstMissingPositive(int* nums, int numsSize){
    int     i           = 0;
    int     iOneFlag    = 0;
    int     iTmpABS     = 0;

    //1,2,查找是否含有1，并且将小于1，大于numsSize 的数字全部修改为1
    for (i = 0; i < numsSize; i++)
    {
        if (nums[i] == 1)
        {
            iOneFlag = 1;
        }
        else if ((nums[i] <= 0) || (nums[i] > numsSize))
        {
            nums[i] = 1;
        }
    }

    if (!iOneFlag) return 1;

    //3,遍历修改后的数组，用数字作为下标，将数组对应位置的元素修改符号
    for (i = 0; i < numsSize; i++)
    {
        iTmpABS = (ABS(nums[i])) % numsSize;

        if (nums[iTmpABS] > 0)
        {
            nums[iTmpABS] = 0 - nums[iTmpABS];
        }
    }
    
    //4,遍历数组，找到第一个正数，下标即为没有出现的最小正整数
    for (i = 1; i < numsSize; i++)
    {
        if (nums[i] > 0)
        {
            break;
        }
    }

    if ((i >= numsSize) && (nums[0] < 0))
    {
        return numsSize + 1;
    }
    else
    {
        return i;
    }
}

/*
//快速排序比较方法，负数不用比较，避免出现临界值报错的情况
int compare(const void* a, const void* b){
    if (*(int*)a < 0)
    {
        return -1;
    }
    else if (*(int*)b < 0)
    {
        return 1;
    }
    else
    {
        return *(int*)a - *(int*)b;
    }
}

//方法一：
//1,快速排序输入数组，时间复杂度上不满足要求
//2,对有续数组进行遍历查找没有出现的最小正整数
int firstMissingPositive(int* nums, int numsSize){
    int     i       = 0;
    int     iRet    = 0;
    int     iTmp    = 0;
    int     iRepeat = 0;

    if ((NULL == nums) || (0 == numsSize)) return 1; 

    //1,快速排序
    qsort(nums, numsSize, sizeof(int), compare);

    //2,找出缺失的最小正整数
    for (i = 0; i < numsSize; i++)
    {
        if (nums[i] <= 0)
        {
            //iTmp 标记第一个大于0的数的位置
            iTmp = i + 1;
//            printf("[1] i=%d, iTmp=%d, val=%d\n", i, iTmp, nums[i]);

            if (iTmp >= numsSize)
            {
                return 1;           //特殊处理，所有数都小于0则直接返回1
            }
            continue;
        }
        else
        {
            if (nums[iTmp] != 1)
            {
                //特殊处理，第一个大于0的数如果不等于1则直接返回1
                return 1;
            }

//            printf("[2] i=%d, iTmp=%d, val=%d\n", i, iTmp, nums[i]);

            //处理从1开始的情况，iRepeat记录出现重复数字的次数
            if ((i > 0) && (nums[i - 1] == nums[i]))
            {
                //
                iRepeat += 1;
            }

            //根据 i iRepeat iTmp 能够直接推算出下一个数字，如果不是则找出了不连续的位置
            if (nums[i] != i + 1 - iRepeat - iTmp)
            {
                break;
            }
        }
    }

    return nums[i - 1] + 1;
}
*/
```