### 解题思路
算法方法就和三数和一样，就不说了。

关于动态数组开辟大小的问题，我们可以用组合的方式来做。
就是从一堆数里随机选取4个，共有几种情况。用Cn4 就行了，但是内存竟然消耗了73MB！
细想之后，其实选定3个数，第四个数就唯一确定了，因为target是固定的，
所以我们用Cn3 就可以包含题目所有情况，这次内存消耗为13MB！
当然，会看到我的代码3 4都有，原因是Cnm，m等于n的一半的时候，取值是最大的。
随机选4个数，是包含选3个数的情况的，所以选3 4都可以，但我们要选择占用空间小的。

虽然选择了Cn3 大大减少了空间，但是13MB只超过了80%，于是又改进了一下，
在数组升序的情况下，target - nums[0]-nums[1]-nums[2],得到的第四个数，是最大的情况了，
比这个数还大的数，是一定排除在外的，也就是大于这个最大数的后半部分，是不用考虑的，（而且这个条件是可以
用在求和的循环里，减少循环次数的）
我们选取的三个数，也就没有必要从这后半部分选，Cnm的 n 也就减小了，这次消耗内存8MB，超过90%。

我在评论区看到大佬的解题，数组开辟大小是（numsSize + 1）* 6。我发现这个空间占用，
在数组长度大于等于8的时候，比我的 Cn3 开辟的空间更小！
但是，我不理解这个式子是怎么得来的？？？？？？


### 代码

```c
#include<stdio.h>
#include<stdlib.h>

int combineNum(int n, int m)   //Cnm 的组合情况
{
    if (n < m)
        return 0;
    if (m == 0)
        return 1;
    if (m == n)
        return 1;
    int temp = (m <= n - m) ? m : n - m;
    unsigned int a = 1, b = 1;
    for (; temp > 0; temp--,n--)
    {
        a *= n;
        b *= temp;
    }
    return a / b;
}

int cmp ( const void  *a , const void  *b ) 
{
	return *(int *)a - *(int *)b;
}

int** fourSum(int* nums, int numsSize, int target, int* returnSize, int** returnColumnSizes)
{
    int **res = NULL;
    *returnSize = 0;
    if (numsSize < 4)
    {
        return res;
    }
    qsort(nums, numsSize, sizeof(int), cmp);
    int sum_start = nums[0] + nums[1] + nums[2] + nums[3];
    int sum_end = nums[numsSize - 1] + nums[numsSize - 2] + nums[numsSize - 3] + nums[numsSize - 4];
    if (sum_start > target || sum_end < target)
    {
        return res;
    }
    int len = 3;
    for (int i = 3; i < numsSize && nums[i] <= (target - nums[0] - nums[1] - nums[2]); i++)
    {
        len ++;
    }
    if (len < 8)
        res = (int**)calloc(combineNum(len, 4), sizeof(int*));
    else
        res = (int**)calloc(combineNum(len, 3), sizeof(int*));
    if (NULL == res)
    {
        exit(0);
    }
    if (len < 8)
        *returnColumnSizes = (int*)calloc(combineNum(len, 4), sizeof(int));
    else
        *returnColumnSizes = (int*)calloc(combineNum(len, 3), sizeof(int));
    for (int i = 0; i < numsSize - 3; i++)
    {
        if (nums[i] > (target - nums[0] - nums[1] - nums[2]))
        {
            break;
        }
        if (i > 0 && nums[i] == nums[i - 1])
        {
            continue;
        }
        for (int j = i + 1; j < numsSize - 2; j++)
        {
            if (j > i + 1 && nums[j] == nums[j - 1])
            {
                continue;
            }
            int left = j + 1, right = numsSize - 1;
            while (left < right)
            {
                int sum = nums[i] + nums[j] + nums[left] + nums[right];
                if (sum == target)
                {
                    res[*returnSize] = (int*)calloc(4, sizeof(int));
                    if (NULL == res[*returnSize])
                    {
                        exit(0);
                    }
                    (*returnColumnSizes)[*returnSize] = 4;
                    res[*returnSize][0] = nums[i];
                    res[*returnSize][1] = nums[j];
                    res[*returnSize][2] = nums[left];
                    res[*returnSize][3] = nums[right];
                    (*returnSize)++;
                    while (left < right && nums[left] == nums[left + 1])
                    {
                        left ++;
                    }
                    while (left < right && nums[right] == nums[right - 1])
                    {
                        right --;
                    }
                    left ++;
                    right --;
                }
                else if (sum > target)
                {
                    right --;
                }
                else
                {
                    left ++;
                }
            }
        }
    }
    return res;
}
```