### 解题思路
1、一定是使用一个数组记录中间结果，并且从小值记录到大值；
2、需要提前想好大值怎么根据小值计算出来；
3、跟递归一样，定义好边界条件；
4、非常类似递归，好像是吧递归用户组的迭代循环实现了；

### 代码

```python
class Solution(object):
    def climbStairs(self, n):
        """
        dp[i] = dp[i-1] + dp[i-2]
        :type n: int
        :rtype: int
        """

        if n == 0:
            return 0
        if n == 1:
            return 1
        if n == 2:
            return 2

        dp = [0] * (n + 1)
        dp[0] = 0
        dp[1] = 1
        dp[2] = 2
        for i in range(3, n + 1):
            dp[i] = dp[i - 1] + dp[i - 2]
        return dp[n]

```