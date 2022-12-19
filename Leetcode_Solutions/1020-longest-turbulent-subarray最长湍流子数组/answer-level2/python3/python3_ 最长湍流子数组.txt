```python
def maxTurbulenceSize(A):
    """
        1. dp问题: 这里我们不应该关注数值本身, 而是应该关注变化的趋势.
            所以, 对于A = [9,4,2,10,7,8,8,1,9], 变更为: [-1, -1, 1, -1, 1, 0, -1, 1]
            A[i+1]>A[i], 则为1, A[i+1]=A[i], 则为0, 否则为-1
        2. dp[i] = dp[i-1] + 1, 如果nums[i], nums[i-1]为1, -1.(代表上升下降, 或者下降上升)
            dp[i] = 1, 如果nums[i] == nums[i-1](代表上升上升, 或者下降下降)
            dp[i] = 0, 如果nums[i] = 0(代表之前的两数相等)
    """
    if len(A) == 1:
        return 1
    nums = []
    for i in range(1, len(A)):
        v = A[i] - A[i-1]
        nums.append(1 if v > 0 else 0 if v == 0 else -1)
    print(nums)
    dp = [0 for _ in range(len(nums))]
    dp[0] = 0 if nums[0] == 0 else 1
    for i in range(1, len(nums)):
        if nums[i] == 0:
            dp[i] = 0
        elif nums[i] + nums[i-1] == 0:
            dp[i] = dp[i-1] + 1
        else:
            dp[i] = 1
            
    return max(dp) + 1

print(maxTurbulenceSize([9,4,2,10,7,8,8,1,9]))
```