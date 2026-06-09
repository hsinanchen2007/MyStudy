```python
# 暴力递归，超时！O(2^n), O(2^n)
class Solution(object):
    def climbStairs(self, n):
        """
        :type n: int
        :rtype: int
        """
        return self.helper(0, n)
    def helper(self, i, n):
        if i>n:
            return 0
        if i==n:
            return 1
        return self.helper(i+1, n) + self.helper(i+2, n)

# 记忆化递归 O(n), O(n)
class Solution(object):
    def climbStairs(self, n):
        """
        :type n: int
        :rtype: int
        """
        self.memo = [None]*(n+1)
        return self.helper(0, n)
    def helper(self, i, n):
        if i>n:
            return 0
        if i==n:
            return 1
        if self.memo[i]>0:
            return self.memo[i]
        self.memo[i] = self.helper(i+1, n) + self.helper(i+2, n)
        return self.memo[i]

# 动态规划 O(n), O(n)
class Solution(object):
    def climbStairs(self, n):
        """
        :type n: int
        :rtype: int
        """
        if n==1:
            return 1
        dp = [None]*(n+1)
        dp[1], dp[2] = 1, 2
        for i in range(3, n+1):
            dp[i] = dp[i-1] + dp[i-2]
        return dp[n]

# 斐波那契数 O(N), O(1)
class Solution(object):
    def climbStairs(self, n):
        """
        :type n: int
        :rtype: int
        """
        if n==1:
            return 1
        if n==2:
            return 2
        first, second, third = 1,2,0
        for i in range(3, n+1):
            third = first + second
            first = second
            second = third
        return third
```
