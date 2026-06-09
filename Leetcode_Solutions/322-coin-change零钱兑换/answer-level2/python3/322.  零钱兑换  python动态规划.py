### 解题思路
这道题与打劫房屋那题采用的同种思想，也可以将这道题转化到那道题，采用自底而上的动态规划。
**关键点是要找到状态转移方程。**

我们可以先分析下题目例子，题目要求可以凑成总金额所需的最少的硬币个数。那么怎样确定当前金额需要最少的硬币个数呢？
是不是可以通过+1,+2,+5组成当前的金额，换句话来说是不是可以通过min(f(n-1) + 1, f(n-2) + 1, f(n-5) + 1)(其中f(n)表示金额为n时需要最少的硬币个数)来确定下一次金额所需要最少的硬币个数呢？这样一步一步推算，最终就可以得到所需的最少的硬币个数。


因此状态方程可以表示dp[i] = min(dp[i],dp[n-i]),采用循环迭代coin的种类，求得当前金额在所有coins的种类中所需要最小硬币个数。
初始值dp = [float('inf') for _ in range(amount+1)],float('inf')用来对最后找不到组合进行判定
dp[0] = 0,因为金额从1开始计算。


### 代码

```python
class Solution:
    def coinChange(self, coins: List[int], amount: int) -> int:
        # 动态规划
        # 存在最有子结构
        dp = [float('inf') for _ in range(amount+1)]
        dp[0] = 0
        for i in range(1,amount+1):
            for j in coins:
                if i < j:
                    continue
                dp[i] = min(dp[i],dp[i-j]+1)
        return dp[amount] if dp[amount] != float('inf') else -1
```