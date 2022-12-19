```
import copy
class Solution:
    def canPartition(self, nums: List[int]) -> bool:
        sum_nums = sum(nums)
        if sum_nums % 2 != 0:
            return False
        half = sum_nums // 2
        dp = [False] * (half + 1)
        for i in nums:
            dp1 = copy.copy(dp)
            for j in range(1,half+1):
                if i == j and dp1[j] == False:
                    dp[i] = True
                    continue
                if dp1[j] == True and (i+j) <= half:
                    dp[i+j] = True
            if dp[-1] == True:
                return True
        return dp[-1]
```
