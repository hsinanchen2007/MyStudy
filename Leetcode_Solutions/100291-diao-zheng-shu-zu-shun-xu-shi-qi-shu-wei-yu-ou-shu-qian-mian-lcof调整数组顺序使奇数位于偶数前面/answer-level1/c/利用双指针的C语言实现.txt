### 解题思路
该题较为简单，借用了**双指针**和**插入排序的已排序区间和未排序区间**思想来实现，解决思路如下：
* 入参检查
* 分配并初始化数组
* 将新数组分为**奇数区间**和**偶数区间**。奇数区间**从前向后**插入数据，偶数区间**从后向前**插入数据。因此，创建了双指针进行记录各区间的数组下标。
* 循环遍历nums数组，判断数组元素的奇偶性，并将其插入新数组中

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* exchange(int* nums, int numsSize, int* returnSize)
{
    //入参检查
    if(nums == NULL)
    {
        *returnSize = 0;
        return NULL;
    }

    //分配和初始化数组
    int *result = (int*)malloc(sizeof(int)*numsSize);
    memset(result, 0, sizeof(int)*numsSize);

    int m = 0; //奇数区间指针
    int n = numsSize-1; //偶数区间指针
    for(int i =0; i < numsSize;i++)
    {
        if(nums[i] % 2 == 1)
        {
            result[m] = nums[i];
            m++;
        }
        else
        {
            result[n] = nums[i];
            n--;
        }
    }
    *returnSize = numsSize;
    return result;
}
```