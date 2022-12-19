此题采用动态规划求解，采用动态规划关键在于求出状态转移方程。
因为此题是要求出偷窃的最高金额，所以我们可以自然的想到用DP[i]表示在偷窃到第i(0~n-1)个房屋结束时（第i个房屋的金额既可以偷窃也可以不偷窃），小偷所偷窃到的最高金额。

为了保证最后的金额最大：
状态转移方程分析：
1. 当第i个房屋被偷窃时：显然此时第i-1个房屋不能被偷窃，所以只能有DP[i-2]转移到DP[i]
DP[i] = DP[i-2] + nums[i]

2. 当第i个房屋不被偷窃时：显然此时第i-1个房屋是被偷窃的
DP[i] = DP[i-1]

所以：
DP[i] = max(DP[i-2] + nums[i], DP[i-1])

初始条件：
DP[0] = nums[0]
DP[1] = max(nums[0], nums[1]) %只能偷窃第0个和第1个房屋中的一个房屋

```
class Solution:
    def rob(self, nums: List[int]) -> int:

        n = len(nums)
        if n == 0:
            return 0
        if n == 1:
            return nums[0]
        DP = [0 for i in range(n)]
        DP[0] = nums[0]
        DP[1] = max(nums[0], nums[1])
        for i in range(2, n):
            DP[i] = max(DP[i-2] + nums[i], DP[i-1])
        
        return DP[-1]
```

有写得不明白的地方，可以留言互相交流。
