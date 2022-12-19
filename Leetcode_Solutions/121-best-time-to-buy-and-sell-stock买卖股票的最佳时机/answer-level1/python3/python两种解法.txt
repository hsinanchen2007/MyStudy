# 解法1 双指针
最开始的做法：
暴力法时间复杂度肯定是$n^2$，如果一直维护`min_price`和`max_profit`两个变量，就可以一次遍历解决问题
```
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        min_price = float('inf')
        max_profit = 0
        for i in range(len(prices)):
            min_price = min(prices[i], min_price)
            max_profit = max(max_profit, prices[i]-min_price)
        return max_profit
```

# 解法2 动态规划
做完后参考了其他人的题解，才理解了另一个思路，就把我的理解写一下
由牛顿莱布尼兹公式可得  
$\int_a^b f(x) {\rm d}x = F(x)|^b_a = F(b)-F(a)$

因此，区间和跟求差可以相互转换。题目就变为求最大连续子数组和，用动态规划很好做。可以理解为题目要求最大价格差，我们可以构造一个数组，prices[i]-prices[i-1],代表每日能获得的利润值，这个数组的最大连续子数组和就是最大利润，即最大价格差。  
具体表现为：
- 首先构造diff数组，求连续两天的价格差
- 状态转移方程`dp[i] = max(dp[i-1]+diff[i], 0)`, `dp[i]`指以i元素结尾的子数组的最大和
- 接着遍历diff数组，根据状态转移方程求出dp数组
- 最后dp数组中的最大值就是最大价格差  

**版本一**
```
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        if len(prices)<=1:
            return 0
        diff = [0 for _ in range(len(prices)-1)]
        for i in range(len(prices)-1):
            diff[i] = prices[i+1]-prices[i]
        dp = [0 for _ in range(len(prices)-1)]
        dp[0] = max(0, diff[0])
        max_profit = dp[0]
        for i in range(1, len(prices)-1):
            dp[i] = max(0, diff[i]+dp[i-1])
            max_profit = max(max_profit, dp[i])
        return max_profit
```

由于已经有`max_profit`在记录最大dp值了，所以不需要记录dp数组，浪费空间，用一个临时变量代替即可  
**版本二**
```
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        if len(prices)<=1:
            return 0
        diff = [0 for _ in range(len(prices)-1)]
        for i in range(len(prices)-1):
            diff[i] = prices[i+1]-prices[i]
        temp = max_profit = 0
        for i in range(len(prices)-1):
            temp = max(0, diff[i]+temp)
            max_profit = max(max_profit, temp)
        return max_profit
```

这么看diff数组其实也没有必要  
**版本三**
```
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        temp = max_profit = 0
        for i in range(len(prices)-1):
            temp = max(0, prices[i+1]-prices[i]+temp)
            max_profit = max(max_profit, temp)
        return max_profit
```

# 总结
其实两种都算是动态规划，都是记录之前的值，来更新当前的值。第一种更好理解，记录最低值，不断更新最大高度差。第二种则是经典的动态规划思路，套用经典的求最大连续子数组和就行