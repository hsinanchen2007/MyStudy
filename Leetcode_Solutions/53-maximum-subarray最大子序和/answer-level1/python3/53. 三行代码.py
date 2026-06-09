### 解题思路
参考了一位大神的思路：https://www.bilibili.com/video/av76546842?from=search&seid=7851445025250542669
大概意思就是，循环过程中，将当前数值前的数值之和作为一个整体，如果前序数列之和是负数，那么都不需要考虑，因为无论如何，再减一个数只会更小。

### 代码

```python3
class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        for i in range(1, len(nums)):
            if nums[i-1] > 0:
                nums[i] += nums[i-1]
            
        return max(nums)
```