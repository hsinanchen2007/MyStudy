### 解题思路
O(n)空间O(n)时间的算法都会吧？不说了。
那怎么O(1)空间呢？把所有数都<< 1，最低位就空出来了。
然后原数组就是nums[i] >> 1，nums[i] & 1就用来记录i + 1是否出现过，然后照搬O(n)空间的方法就行了。
那么<< 1的时候会不会溢出呢？不会，因为我们只关心小于等于n的数，超过n或者小于0的数直接删掉，所以最多是2n，不可能溢出。


### 代码

```c
int firstMissingPositive(int* nums, int numsSize)
{
    for (int i = 0; i < numsSize; i++)
        if (nums[i] > 0 && nums[i] <= numsSize)
            nums[i] <<= 1;
        else
            nums[i] = 0;
    for (int i = 0; i < numsSize; i++)
        if (nums[i] >> 1)
            nums[(nums[i] >> 1) - 1] |= 1;
    for (int i = 0; i < numsSize; i++)
        if (!(nums[i] & 1))
            return i + 1;
    return numsSize + 1;
}
```
时间0ms 100%，空间7.2MB 76.34%
喵喵喵？
我可能是申请了一个7.2MB的int i
......