### 解题思路
看到此题的第一反应是将问题分解, 变成一个一个小的问题, 比如10, 就可以考虑1和9, 2和8等. 那么就可以用一个一维数组来保存当前组成该数可以达到的最大的乘积, 比如dp[3]就保存将3拆分后得到的最大的乘积, 然后就是两层遍历逐步更新状态. 有点需要注意的就是动态规划的迭代式, dp[i] = max(max(dp[j], j)*max(dp[i-j], i-j), dp[i]). 这里取最大值的操作是为了处理比如dp[8] = dp[3]*dp[5], 这里可以将3直接当成一个计算数了, 没必要将它拆分, 所以需要取本身和dp[3]两者的最大值. 整体思路就是这样. 

### 代码

```python3
class Solution(object):
    def integerBreak(self, n):
        """
        :type n: int
        :rtype: int
        """
        dp = [0 for i in range(n+1)]
        dp[1] = 1
        dp[2] = 1
        for i in range(3, n+1):
            for j in range(1, i // 2 +1):
                dp[i] = max(max(dp[j], j)*max(dp[i-j], i-j), dp[i])
        return dp[n]
```