### 解题思路
和198.打家劫舍是同一道题，换一个马甲同样认识你。
dp中定义的是当前所能获得的最大的时间长度，当前的每个值都只有两种情况：第一种是要么取当前值，此时的最大时长就是当前值和前面的2的值得和，第二种就是不取当前值，那么当前值得最大的时长就是前面一个值得时间长度，至于取不取当前这个值，max比较一下就可以了。题目说的有点绕，理解一下就能知道了。

### 代码

```

class Solution:
    def massage(self, nums: List[int]) -> int:
        ##典型的动态规划法
        lens = len(nums)
        if lens==0:
            return 0
        if lens==1:
            return nums[0]
        if lens==2:
            return max(nums[0],nums[1])
        dp = nums
        dp[0] = nums[0]
        dp[1] = max(nums[0],nums[1])
        for i in range(2,lens):
            dp[i] = max(nums[i]+dp[i-2],dp[i-1])
        print(dp)
        return max(dp)

```