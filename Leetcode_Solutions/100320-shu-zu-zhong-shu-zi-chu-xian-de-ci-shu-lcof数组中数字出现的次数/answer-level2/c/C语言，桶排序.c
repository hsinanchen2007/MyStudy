### 解题思路
该题没有找到空间复杂度为O(n)的方法，解题思路如下：
1 找到数组中的最大值
2 建立排序数组
2 利用桶排序获取nums数组中每个数据出现的频率
3 找到排序数组中值为1的数组下标

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int maxval(int *arr, int numsSize)
{
    int max = 0;
    if(arr == NULL)
    {
        max = 0;
    }
    else
    {
        max = arr[0];
        for(int i =0; i < numsSize;i++)
        {
            if(arr[i] > max)
            {
                max = arr[i];
            }
        }
    }
    return max;
}

int* singleNumbers(int* nums, int numsSize, int* returnSize)
{
    int max = maxval(nums, numsSize);

    int *result = (int*)malloc(sizeof(int)*(max+1));
    memset(result, 0, sizeof(int)*(max+1));
    int *rel = (int*)malloc(sizeof(int)*2);

    for(int i =0; i < numsSize;i++)
    {
        result[nums[i]]++;
    }

    int k = 0;
    for(int j =0; j <=max;j++)
    {
        if(result[j] == 1)
        {
            rel[k] =j;
            k++;

        }
    }
    *returnSize = 2;
    return rel;
}
```