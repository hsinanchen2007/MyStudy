```python
def rob(nums):
    """
        1. dp问题: dp[i] += max(dp[i-2], dp[i - 3])
        2. 可以转化为a, b = b, max(a + dp[i], b)
        3. 因为首尾连接, 所以分两次判断
    """
    if not nums:
        return 0
    if len(nums) < 4:
        return max(nums)
    a1, b1, a2, b2 = 0, 0, 0, 0
    for i in range(len(nums) - 1):
        a1, b1 = b1, max(a1 + nums[i], b1)
    for i in range(1, len(nums)):
        a2, b2 = b2, max(a2 + nums[i], b2)
    
    return max(b1, b2)

print(rob([2,3,2]))
print(rob([1,2,3,1]))
```