### 解题思路
纯C 两次二分查找

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* searchRange(int* nums, int numsSize, int target, int* returnSize){
    int* pRes = (int*)malloc(2 * sizeof(int));
    memset(pRes, -1, 2 * sizeof(int));
    *returnSize = 2;

    if (NULL == nums || 0 == numsSize)
    {
        return pRes;
    }

    int startRes = -1;
    int endRes = -1;
    int start = 0;
    int end = numsSize - 1;
    int mid = 0;

    // 找开头
    while (start + 1 < end)
    {
        mid = start + (end - start) / 2;

        if (nums[mid] >= target)
        {
            end = mid;
        }
        else 
        {
            start = mid;
        }
    }

    if (target == nums[start])
    {
        startRes = start;
    }
    else if (target == nums[end])
    {
        startRes = end;
    }

    if (-1 == startRes)
    {
        return pRes;
    }

    // 找结尾
    start = 0;
    end = numsSize - 1;

    while (start + 1 < end)
    {
        mid = start + (end - start) / 2;

        if (nums[mid] > target)
        {
            end = mid;
        }
        else
        {
            start = mid;
        }
    }

    if (target == nums[end])
    {
        endRes = end;
    }
    else if (target == nums[start])
    {
        endRes = start;
    }

    pRes[0] = startRes;
    pRes[1] = endRes;

    return pRes;
}
```