### 解题思路
逻辑一般都很清晰，搞清楚初始边界条件即可

### 代码

```python
class Solution(object):
    def minSubArrayLen(self, s, nums):
        """
        :type s: int
        :type nums: List[int]
        :rtype: int
        """
        if sum(nums) < s:return 0
        res = len(nums)
        tot = 0
        i = 0
        for j in range(len(nums)):
            tot += nums[j]
            while tot >= s:
                res = min(res,j - i + 1)
                tot -= nums[i]
                i += 1
        return res
```