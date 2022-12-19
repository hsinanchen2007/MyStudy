# Python
```
class Solution(object):
    def climbStairs(self, n):
        """
        :type n: int
        :rtype: int
        """
        if n < 3:
            return n;
        dp = [1,2]
        for i in range(2, n):
            dp.append(dp[i-1] + dp[i-2])
        return dp[-1]
```
```
class Solution(object):
    def climbStairs(self, n):
        """
        :type n: int
        :rtype: int
        """
        if n < 3:
            return n;
        f1, f2, f3 = 1, 2, 3;
        for i in range(3, n):
            f1 = f2;
            f2 = f3;
            f3 = f1 + f2;
        return f3
```
# Java
```
class Solution {
    public int climbStairs(int n) {
        if (n < 3) {
            return n;
        }
        int f1 = 1;
        int f2 = 2;
        int f3 = 3;
        for (int i = 3; i < n; i++) {
            f1 = f2;
            f2 = f3;
            f3 = f1 + f2;
        }
        return f3;
    }
}
```
