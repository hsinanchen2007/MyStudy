```python
class Solution:
    def canPartition(self, nums: List[int]) -> bool:
        arr_sum = sum(nums)
        if arr_sum % 2 == 1: return False
        target = arr_sum // 2
        dp = [False] * (target + 1)
        for i in range(len(nums)):
            for j in reversed(range(target + 1)): # traverse reversely
                if nums[i] == j:
                    dp[j] = True
                    continue
                if nums[i] < j:
                    dp[j] = dp[j] or dp[j - nums[i]]
            if dp[target] == True: return True
        return False
```