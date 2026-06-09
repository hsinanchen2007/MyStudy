Python3 版本

[一个通用方法团灭 6 道股票问题](https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-iii/solution/yi-ge-tong-yong-fang-fa-tuan-mie-6-dao-gu-piao-wen/)
和前几题不同的是需要处理k
k正着还是倒着，就看前面桌面定义的，  
1、正着定义base case时，k代表已交易次数，从0开始，0，1  
2、倒着定义base case时，k代表剩余交易次数，从2开始，2，1
```python3
    # 一个方法团灭 6 道股票问题
    # dp[i][k][0 or 1] 在i天还剩k次交易次数，1持有 0不持有
    # dp[i][k][0] = max(dp[i-1][k][0], dp[i-1][k][1] + prices[i]) 不动，昨天持有，今天卖了, + prices[i]
    # dp[i][k][1] = max(dp[i-1][k][1], dp[i-1][k-1][0] - prices[i]) 不动，昨天没有，今天买入, - prices[i]
    def maxProfit(self, prices: List[int]) -> int:
        if len(prices)<=1:return 0
        maxk = 2
        dp = [[[0, 0] for i in range(maxk+1)] for i in range(len(prices))]
        dp[0][2][0] = 0                         #第0天，不管还剩几次交易次数，不持有收益是0，也不可能持有(一天内不能瞬间买入卖出)，所以设1为负数
        dp[0][2][1] = -prices[0]                                                
        dp[0][1][0] = 0                                                         
        dp[0][1][1] = -prices[0]                                                
        for i in range(1, len(prices)):
            for k in range(maxk, 0, -1):        #这里必须倒着，base case中k是倒着的，这里正序会出现0，1，与前面的设定不同了，就会出错
                dp[i][k][0] = max(dp[i-1][k][0], dp[i-1][k][1] + prices[i])
                dp[i][k][1] = max(dp[i-1][k][1], dp[i-1][k-1][0] - prices[i])   
        return dp[-1][maxk][0]                  #不持有就是卖出了，卖出肯定比持有收益多
```
