### 解题思路
利用动态规划解题
边界：当n=1,f(n)=1,n=2,f(2)=2
状态转移方程：f(n)= f(n-1)+f(n-2),首先考虑最后一步的情况,要么从第n-1级台阶再走一级到第n级,要么从第n-2级台阶走两级到第n级,因而,要想到达第n级台阶,最后一步一定是从第n-1级或者第n-2级台阶开始.也就是说已知从地面到第n-2级台阶一共有X种走法,从地面到第n-1级台阶一共有Y种走法,那么从地面到第n级台阶一共有X+Y种走法.
### 代码

```python
class Solution(object):
    def numWays(self, n):
        """
        :type n: int
        :rtype: int
        """
        # 边界
        if n==0:
            return 1
        if n<=2:
            return n
        a = 1
        b = 2
        for i in range(2,n):
            sum = a+b
            a = b
            b = sum
        return sum%1000000007
```