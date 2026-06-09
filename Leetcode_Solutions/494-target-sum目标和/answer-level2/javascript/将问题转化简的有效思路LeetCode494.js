# 如何有效化简此题呢？
1. 此题有些类似于小学奥数“鸡兔同笼”问题，那么首先，可以假设所有的符号都是+的，然后再考虑把哪些符号转成负的，这样问题就从完整的2进制状态数枚举转化成了01背包问题。
2. 当全部符号为正时，和是sum(nums)，如果有一个数取负，那么就要减去2*nums[i]，问题就转化为：取出哪些nums[i]使他们的值的和等于S。
3. 我们把问题描述成公式即是sum(nums)-2*(背包值) = S，所求背包值=(sum(nums)-S)/2。
4. 数组为nums，背包大小为S，求和为S的大小背包方案数，那么就可以通过限制背包大小做到剪枝。

```
class Solution:
    def findTargetSumWays(self, nums: List[int], S: int) -> int:
        #问题先转化为：先假设所有的符号为+，此时和为sum(nums)，这么多值，问题就转化为： 就是 ,问题即转化为求出背包值等于 sum(nums)-S的0-1背包方案数
        if (S+sum(nums))%2!=0 or sum(nums)<S:return 0
        target = (sum(nums)-S)//2
        dp = [0]*(target+1)
        dp[0]=1
        for num in nums:
            for i in range(target,num-1,-1):
                dp[i]+=dp[i-num]
        return dp[target]
```

