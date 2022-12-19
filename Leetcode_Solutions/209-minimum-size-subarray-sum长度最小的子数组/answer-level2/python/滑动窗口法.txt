就是标准的滑动窗口法，双指针移动。
```
class Solution(object):
    def minSubArrayLen(self, s, nums):
        """
        :type s: int
        :type nums: List[int]
        :rtype: int
        """
        if not nums or len(nums) == 0:
            return 0
        start,end = 0,0
        tmp_sum = 0
        res = float('inf')
        while end < len(nums):
            tmp_sum += nums[end]
            end += 1
            while tmp_sum >= s:
                res = min(res,end-start)
                tmp_sum -= nums[start]
                start += 1
        return 0 if res == float('inf') else res
```
