### 解题思路
内存超过100%用户 但速度不快

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* exchange(int* nums, int numsSize, int* returnSize)
{
    int a = 0, b = numsSize - 1;
    int tmp;
    while (a < b)
    {
        if (!(nums[a] & 1) && nums[b] & 1) tmp = nums[a], nums[a] = nums[b], nums[b] = tmp,
        a++, b--;
        if (nums[a] & 1) a++;
        if (!(nums[b] & 1)) b--;
    }
    *returnSize = numsSize;
    return nums;
}
```