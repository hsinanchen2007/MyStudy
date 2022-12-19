标准的滑动窗口法，双指针法。
```
class Solution(object):
    def maxSlidingWindow(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: List[int]
        """
        start,end = 0,0
        cnt = 0
        res,tmp = [],[]
        while end < len(nums):
            cnt += 1
            tmp.append(nums[end])
            end += 1
            while cnt > k:
                tmp.remove(nums[start])
                start += 1
                cnt -= 1
            if cnt == k:
                res.append(max(tmp))
        return res
```
