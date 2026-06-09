其实，只需要思考最大子序和的构成就能快速理解动态规划在这道题上的应用了。
首先，最大子序和的结束点可以在数组中的任一位置，这个我们不知道，所以需要遍历每个元素作为结束点。
一个元素如果是最大子序和的结束点，那么这个最大子序的构成只有两种可能：1. 这个元素本身。2. 这个元素+以前一个元素为结束点的最大子序和。
![绘图1.jpg](https://pic.leetcode-cn.com/d3dab92b956682c641741081b5e14641c207ad4e970d8494719a62ac5aec3ebc-%E7%BB%98%E5%9B%BE1.jpg)
```
def maxSubArray(nums):
    dp = [0] * len(nums)
    dp[0] = nums[0]

    for i in range(1, len(nums)):
        dp[i] = max(dp[i-1] + nums[i], nums[i]) #动态规划核心步骤

    return max(dp)
```

