
dp[i]:打劫前(i+1)个房屋能获取的最大收益

dp[i]= max(dp[i-2]+nums[i],dp[i-1])

dp[0]=nums[0]
dp[1] =max(nums[0],nums[1])
