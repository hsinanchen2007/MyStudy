### 解题思路
此处撰写解题思路

### 代码

```python
class Solution(object):
    def maximumGap(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        nums = sorted(list(set(nums)))
        gap = 0
        for i in xrange(1, len(nums)):
            tmp = nums[i] - nums[i-1]
            gap = max(tmp, gap)
        return gap

```