其实这个问题还有一个变形，就是求能够组成[1,amount]中所有值得最少硬币数，我觉得更有挑战性一点（2019腾讯开发岗实习生笔试第一题）

可以参考:

**[硬币问题——组成一个值和组成所有值(腾讯笔试题)](https://www.cnblogs.com/anzhengyu/p/11176134.html)**

###  动态规划
dp[i] = 1 + min(dp[i-coins[0]],dp[i-coins[1]],dp[i-coins[2]]...)

写的罗里吧嗦的乐色算法......
代码如下：
```
class Solution:
    def coinChange(self, coins: List[int], amount: int) -> int:
        if amount ==0:   # 总数为0，消耗钱为0
            return 0
        if amount < min(coins):   # 总数比所有的硬币面值都小，无解
            return -1
        dp = [0 for i in range(amount+1)]
        for coin in coins:        # 初始化dp数组
            if coin<=amount:
                dp[coin]= 1
        for i in range(1,amount+1):
            if dp[i]==1:
                continue
            min_ = 100000
            for j in coins:
                if i-j>0:
                    min_ = min(min_,dp[i-j]+1)        
            dp[i] = min_
        if dp[-1]<100000:
            return dp[-1]
        else:
            return -1
```
