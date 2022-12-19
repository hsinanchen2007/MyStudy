### 解题思路
优先用贪婪，遇到一个非零数字，则跳跃到最大的位置，直到失败前都继续前进。
对很多用例，此方法时间复杂度小于Ｏ(N)

如果遇到０，则回溯，在起跳点和０之间寻找一个能跨过０的数字继续。
如果用例０很多，那最坏也是Ｏ(N)

但可能是因为用了递归的实现，实际效果不是很明显。

### 代码

```c
bool backtrack(int *nums, int numsSize, int i)
{
    if (i >= numsSize - 1)
        return true;
    if (nums[i] == 0)
        return false;
    if (backtrack(nums, numsSize, i + nums[i]))
        return true;
    for (int idx = i + 1; idx < i + nums[i] && idx < numsSize; idx++)
        if (nums[idx] + idx > i + nums[i] && backtrack(nums, numsSize, idx))
            return true;
    return false;
}
bool canJump(int *nums, int numsSize)
{
    return backtrack(nums, numsSize, 0);
}
```