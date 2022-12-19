### 解题思路
遇到这类求最大值最优解问题，第一个冒出来的想法就是DP动态规划,只要把各个状态都设计好，理解起来很比较简单
1. 思考子问题 
   总的最大分钟数等于前一次的最大分钟数，加上or不加本次的分钟数，依次可以递推每一次的情况。
2. DP数组 
   dp[i][k] i为具体哪一天，k为接客or不接客 0不接，1接
   在实际处理的时候要增加一层dp[0]，来解决计算逻辑问题，dp[0][0] = 0, dp[0][1]等于0，因为没有任何的接客安排，所以都取0就好
3. DP方程 
  dp[i][0] = max(dp[i-1][0], dp[i-1][1])  今天休息就是上一次休息今天继续休息和上一次接客了今天休息，取其中最大值
  dp[i][1] = dp[i-1][0] + income 今天接客的累计收入就是上一次休息后的最高收入+今天的收入
下面看代码把，其实挺简单的
### 代码

```python

class Solution(object):
    def massage(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        
        if not nums:
            return 0
        
        n = len(nums)

        dp = [[0,0] * 1 for _ in range(n+1)]
        
        for i in range(1,n+1):
            dp[i][0] = max(dp[i-1][0], dp[i-1][1])
            dp[i][1] = dp[i-1][0] + nums[i-1]

        return max(dp[n][0], dp[n][1])
```