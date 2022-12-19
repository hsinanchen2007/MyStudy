### 解题思路
开始用的回溯搜索，结果当然超时，后来看到题解，用动态规划，dp[i]代表i时刻组成的最小解，如果每个部分都是最小值，那自然以后的值都是最小值，需要注意的要初始值都要设置为无穷，要不然无法判断是否能组成值。
$dp[i]=min(dp[i-1],dp[i-2],dp[i-5])$按照这个状态转移层层迭代下去，然后得到最后一个值即可。初始值dp[0]要设置为0.

### 代码

```python
class Solution(object):
    def coinChange(self, coins, amount):
        """
        :type coins: List[int]
        :type amount: int
        :rtype: int
        """
        res=[float('inf')]*(amount+1)
        res[0]=0
        for i in coins:
            for j in range(1,amount+1):
                if j-i>=0:
                    res[j]=min(res[j],res[j-i]+1)
        print(res)
        if res[-1]!=float('inf'):
            return res[-1]
        return -1
```