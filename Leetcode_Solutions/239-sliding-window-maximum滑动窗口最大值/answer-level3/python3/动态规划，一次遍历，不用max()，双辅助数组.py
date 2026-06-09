动态规划，一次遍历，不用max函数，全程使用基本数组和数组下标。借用两个动态规划的数组
```
L = len(nums)
dp = [float("-inf") for i in range(L)] #储存每个位置被影响到的最大值
pos_dp = [float("inf") for i in range(L)] #储存dp中对应位置的值的影响范围，pos_dp[i]表示dp[i]的值影响到dp[pos_dp[i]]之前
for i in range(L):
    if nums[i] >= dp[i]: #大于没什么好说的，往dp中储存当前nums[i]对后续的影响
        dp[i] = nums[i]
        if i + k <= L:
            dp[i + 1:i + k] = [nums[i]] * (k - 1)
            pos_dp[i + 1:i + k] = [i + k] * (k - 1)
        else:
            dp[i + 1:] = [nums[i]] * (L - i - 1)
            pos_dp[i + 1:] = [i + k] * (L - i - 1)
    else: #nums[i]<dp[i]时，需要确定这个较小的nums[i]对于dp后续位置的影响范围，用start来表示起始的影响坐标
        start = i
        while start < L and start - i <= k - 1:
            if nums[i] < dp[start]: #通过比较nums[i]和dp[start]，并查询pos_dp，最终确定start
                start = pos_dp[start]
            else:
                break
        if start <= i+k-1 <= L-1:
            dp[start:i + k] = [nums[i]] * (i + k - start)
            pos_dp[start:i + k] = [i + k] * (i + k - start)
        elif start <= L-1 < i+k-1:
            dp[start:] = [nums[i]] * (L - start)
            pos_dp[start:] = [i + k] * (L - start)
return dp[k-1:]
```
