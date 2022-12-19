### 解题思路
对于有序数组或者多部分有序数组的查找问题99.999999%都是用二分查找，这道题其实考察的是二分查找的两个常见拓展之一，即查找目标序列的左边界，另一个常见拓展是查找目标序列的右边界。
乍一看，这道题好像看不出来是这两个拓展啊，那是因为我们已经见惯了太多的在递增或者递减序列中查找连续相同元素的左边界或者右边界这种基础问题，一定要理解这里的**连续**目标序列是指满足一定条件即可，比如这道题，满足条件的序列就是nums[i] == i + 1（因为少了一个元素，错开了），那么寻找缺少的不就是目标序列的左边界吗？

### 代码

```python
class Solution(object):
    def missingNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        length = len(nums)
        left = 0
        right = length - 1
        mid = (left + right) // 2
        while left <= right:
            if nums[mid] != mid:
                right = mid - 1
            else:
                left = mid + 1
            mid = (left + right) // 2
        return left
```