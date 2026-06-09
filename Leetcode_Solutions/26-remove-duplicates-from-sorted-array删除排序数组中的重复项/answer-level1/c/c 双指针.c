### 解题思路
双指针替换。

### 代码

```c
int removeDuplicates(int *nums, int numsSize)
{
    if (numsSize <= 1)
        return numsSize;

    int i = 0;
    for (int j = 1; j < numsSize; j++)
    {
        if (nums[i] != nums[j])
        {
            nums[++i] = nums[j];
        }
    }
    return i+1;
}

```