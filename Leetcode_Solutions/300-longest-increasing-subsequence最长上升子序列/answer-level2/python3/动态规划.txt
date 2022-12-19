```
class Solution:
    def lengthOfLIS(self, nums: List[int]) -> int:
        '''
        思路：动态规划
             nums = [..., Ai, ...], dp(k)表示以Ak结尾的最大上升子串的长度
             我们知道，dp[k]最小==1，因为若以Ak结尾的子串，当Ai>Ak时,那么只能自身为一个子串，
             不可能连接Ai构成上升子串。所以，我们只要考虑Ai<Ak 的情况：
             dp[k] = max{dp[k],dp[k]+1 | Ak>Ai; i in range(k)}
        '''
        if not nums:
            return 0
        dp = [1 for i in range(len(nums))]
        for k in range(1,len(nums)):
            for i in range(0,k):
                if nums[k] > nums[i]:
                    dp[k] = max(dp[k],dp[i]+1)
        return max(dp)
```
