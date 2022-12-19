## 分类讨论
这种题目关键在于理清思路，分类讨论每一种情况才可以。

因为数组长度是固定，所以时间复杂度和空间复杂度均为O(1).

```python
class Solution:
    def isStraight(self, nums: List[int]) -> bool:
        notZeroNums = [num for num in nums if num != 0]
        zeroNum = 5 - len(notZeroNums)
        # case1： 除0外有重复数字
        if len(notZeroNums) != len(set(notZeroNums)):
            return False
        # case2: 除0外无重复数字
        notZeroNums = sorted(notZeroNums)
        gap = 0
        for i in range(1, len(notZeroNums)):
            gap += notZeroNums[i] - notZeroNums[i-1]
        return gap <= 4

```