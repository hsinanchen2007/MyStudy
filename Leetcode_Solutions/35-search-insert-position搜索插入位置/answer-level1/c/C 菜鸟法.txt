### 解题思路
主要考虑边界的特殊情况即可，防止溢出

执行用时 :4 ms, 在所有 C 提交中击败了97.82%的用户
内存消耗 :5.6 MB, 在所有 C 提交中击败了100.00%的用户

### 代码

```c
int searchInsert(int* nums, int numsSize, int target)
{
    int i=0;
    if(numsSize==0)
        return i;
    if(target>nums[numsSize-1])
        return numsSize;
    while(nums[i]<=target&&i<numsSize)
    {
        if(nums[i]==target)
            return i;
        else
            i++;
    }
    return i;
}
```