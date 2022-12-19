
dp是数组下标为i时的最大收益则有
dp[i+1] = max(dp[i],dp[i-1]+nums[i])
![image.png](https://pic.leetcode-cn.com/884faecddf99c5907c5161e8dd6dcbc1dd8a7f6aff169900f20d3c78a3350025-image.png)

def rob(nums):

    m = len(nums)

    if not m:
        return 0

    dp = [0] * (m + 1)

    dp[1] = nums[0]

    for i in range(1,m):

        dp[i+1] = max(dp[i], dp[i-1]+nums[i])

    print(dp)
    return dp[-1]