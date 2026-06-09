### 解题思路
直观的排序，计数

### 代码

```python
class Solution(object):
    def longestConsecutive(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        cnt = len(nums)
        if cnt <= 1:
            return cnt
        nums = sorted(nums)
        cur = 1
        max_len = 1
        for i in xrange(1, cnt):
            if nums[i] == (nums[i-1] + 1):
                cur = cur + 1
                max_len = max(max_len, cur)
            elif nums[i] == nums[i-1]:
                continue
            else:
                cur = 1
        return max_len

```