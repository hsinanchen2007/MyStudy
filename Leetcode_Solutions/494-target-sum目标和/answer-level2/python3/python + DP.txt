```python
class Solution:
    def findTargetSumWays(self, nums: List[int], S: int) -> int:
        # Time complexity: O(sum * N)
        # Space complexity : O（sum)
        sumNums = sum(nums)
        if S > 1000 or S < -1000: return 0
        dp = [[0] * 2002 for _ in range(len(nums) + 1)]
        dp[0][1000] = 1
        tmp_sum = 0
        for i in range(1, len(nums) + 1):
            num = nums[i - 1]
            for j in range(- tmp_sum, tmp_sum + 1):
                dp[i][j + num + 1000] += dp[i - 1][j + 1000]
                dp[i][j - num + 1000] += dp[i - 1][j + 1000]
            tmp_sum += num
        return dp[len(nums)][S + 1000]
```