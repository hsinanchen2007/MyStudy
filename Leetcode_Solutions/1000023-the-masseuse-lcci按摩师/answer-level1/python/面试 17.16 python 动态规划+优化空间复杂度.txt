```python
class Solution(object):
    def massage(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        # 空间复杂度为O（1）
        cur,pre = 0,0
        for i in range(0,len(nums)):
            cur,pre = max(pre+nums[i],cur),cur
        return cur


        
        # 空间复杂度为O（n）
        # dp[i] = max(dp[i-2]+num,d[i-1])
        dp = [0,0]
        for i in range(2,len(nums)+2):
            dp.append(max(dp[i-2]+nums[i-2],dp[i-1]))
        return dp[-1]
```