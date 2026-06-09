### 解题思路
此处撰写解题思路

### 代码

```c
int maxSubArray(int *nums, int numsSize)
{
    int low = 0, sum = nums[0], Extent_sum = 0;
    while (low < numsSize)
    {
        Extent_sum = 0;
        for (int i = low; i < numsSize; i++)
        {
            Extent_sum += nums[i];
            if (sum < Extent_sum)
                sum = Extent_sum;
        }
        low++;
    }
    return sum;
}
```