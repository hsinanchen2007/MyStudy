### 解题思路
纯C

### 代码

```c
int firstMissingPositive(int* nums, int numsSize){
    if (NULL == nums || 0 == numsSize)
    {
        return 1;
    }

    int index = 0;
    int value = 0;

    // 处理负数
    for (index = 0; index <= numsSize - 1; index++)
    {
        if (nums[index] <= 0)
        {
            nums[index] = INT_MAX;
        }
    }

    // 处理正数
    for (index = 0; index <= numsSize - 1; index++)
    {
        value = abs(nums[index]);

        if (value <= numsSize)
        {
            nums[value - 1] = -abs(nums[value - 1]);
        }
    }

    // 找正数
    for (index = 0; index <= numsSize - 1; index++)
    {
        if (nums[index] > 0)
        {
            return index + 1;
        }
    }

    return numsSize + 1;
}
```