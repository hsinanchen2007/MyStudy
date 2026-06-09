```
class Solution(object):
    def maxSumOfThreeSubarrays(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: List[int]
        """
        L = len(nums)
        nums = nums + [0 for i in range(k)]
        last_dp = [(0, [L + k]) for i in range(L + k)]

        for j in range(3):
            dp = [(0, L) for i in range(L)]
            s1 = sum([nums[i] for i in range(L- k -j*k, L - j * k)])
            max_1 = 0
            for i in range(L - k-j*k, -1,-1):
                s1 = s1 - nums[i + k] + nums[i]
                if s1 + last_dp[i + k][0] >= max_1:
                    max_1 = s1 + last_dp[i + k][0]
                    part = [max_1, [i] + last_dp[i + k][1]]
                dp[i] = part
            last_dp = dp
        return last_dp[0][1][:-1]
```
