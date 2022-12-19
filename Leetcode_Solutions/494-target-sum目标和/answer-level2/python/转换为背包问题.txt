该题难点在于，如何将其转换为背包问题。

假设有集合 N 和 集合 P 使得 `sum(N) - sum(P) = S` 其中 N，P 均是输入数组的子集, 那么必然有
```
2*sum(N) - sum(P) + sum(P) = S + sum(N) + sum(P)
=>
2*sum(N) = S + sum(nums)
```
所以我们只需要找到满足上述推论的集合 N 就 ok 了，即转换为问题：存在一个容量为 V 的背包，从 nums 中任意抽取一定数量的数，使得背包恰好被放满，有多少种放法。这个容量 V 我们通过上述的推导已经求出来了, V = sum(N)。

直接给出代码吧：
```
class Solution(object):
    def findTargetSumWays(self, nums, S):
        """
        :type nums: List[int]
        :type S: int
        :rtype: int
        """
        # 如果 nums 的总和都小于 S，肯定是不行的
        # 如果求出的容量 V 是一个浮点数也不符合要求
        if (sum(nums) + S) % 2 != 0 or sum(nums) < S:
            return 0
        # 求背包容量
        V = (sum(nums) + S)//2
        # dp[i] 表示此时背包容量为 i
        dp = [0] * (V + 1)
        # 为什么 dp[0] 取 1 ？ 因为当背包容量为 0 时，
        # 显然我们不需要取任何数到背包即满足条件，所以可行解为 1
        dp[0] = 1
        for num in nums:
            i = V
            while i >= num:
                # dp[i] 的解法数为自身加上dp[i-num]的解法数
                # 这里为什么会如此，可以参考斐波那契数列
                # 这里我可以不放 num 进背包，解法数为 dp[i]
                # 将 num 放进背包，解法数为 dp[i-num]
                # 所以此时的总解法数为 二者和
                dp[i] = dp[i] + dp[i-num]
                i -= 1 # 背包容量减 1
        return dp[V]
```


搜索订阅号 Apelife  
关注后回复 图解，分享给你leetcode动态图解解题集  
定期为大家分享题解，学习经验，解题思路等  