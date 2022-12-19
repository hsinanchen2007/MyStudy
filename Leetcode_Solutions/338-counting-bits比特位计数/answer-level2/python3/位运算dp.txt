正如求一个数中1的个数那样，i&(i-1)中1的个数一定比少1，而且i&(i-1) < i 满足拓扑序可以dp:
```
class Solution:
    def countBits(self, num: int) -> List[int]:
        dp = [0 for _ in range(num+1)]
        for i in range(1, num+1):
            dp[i] = dp[i&(i-1)] + 1
        return dp
```
总结一下常见的位运算dp可以有:
i & j < i
i | j > i
i << k > i
i >> k < i
但凡有这种大小关系都可以拿来DP