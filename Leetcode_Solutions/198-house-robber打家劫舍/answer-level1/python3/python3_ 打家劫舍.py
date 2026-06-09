```python
def rob(nums):
    """
        1. dp问题, dp[i] = max(dp[i] + dp[i - 2], dp[i] + dp[i - 3])
    """
    # 边界条件的判断
    if not nums:
        return 0
    if len(nums) <= 2:
        return max(nums)
    # dp[i] += max(dp[i - 2], dp[i - 3]), 因为i-4 = 两个 i - 2
    nums[2] += nums[0]
    for i in range(3, len(nums)):
        nums[i] += max(nums[i - 2], nums[i - 3])
    return max(nums[-1], nums[-2])

print(rob([1,2,3,1]))
print(rob([2,7,9,3,1]))
```