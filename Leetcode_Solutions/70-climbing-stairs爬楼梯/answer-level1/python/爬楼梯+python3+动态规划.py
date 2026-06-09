
### 动态规划1
基本思路：状态转移方程：dp[i] = d[i-2]+dp[i-1]，先求出初始状态的dp[0]和dp[1]，然后用动态规划解决（其实就是斐波那契数列）：
```
 class Solution:
    # dp[i] = dp[i-1]+dp[i-2]
    def climbStairs(self, n: int) -> int:
        dp = []
        dp.append(1) # 初始状态，只有1阶的时候有一种走法
        dp.append(2) # 有2阶的时候有两种走法
        if n==1:
            return 1
        if n==2:
            return 2
        for i in range(2,n):
            dp.append(dp[i-1]+dp[i-2])
            
        return dp[-1]
```
### 动态规划2
其实就是减少了空间的存储，但是时空复杂度好很多，建议用这个。
```
class Solution:
    # dp[i] = dp[i-1]+dp[i-2]
    def climbStairs(self, n: int) -> int:
        p = 1
        q = 2
        if n==1:
            return 1
        if n==2:
            return 2
        for i in range(2,n):
            p,q = q,p+q
            
        return q
```
