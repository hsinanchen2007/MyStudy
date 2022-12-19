### 解题思路
这道题是一道典型的动态规划题，子问题是f(n) = f(i) * f(n - i)，从思路上做是很简单的，但是需要注意的是，对于n = 2, 3需要单独返回，并且在对dp数组初始化的时候，dp[1], dp[2], dp[3]的初始化并不等于n为1, 2, 3（题中也明确了n > 1）的。

### 代码

```python
class Solution(object):
    def integerBreak(self, n):
        """ 
        :type n: int
        :rtype: int
        """
        if n == 2:
            return 1
        elif n == 3:
            return 2
        dp = [0] * (n + 1)
        dp[1] = 1
        dp[2] = 2
        dp[3] = 3
        for i in range(4, n + 1):
            max_num = 0
            for j in range(1, i // 2 + 1):
                print(j)
                temp = dp[j] * dp[i - j]
                if max_num < temp:
                    max_num = temp
            dp[i] = max_num
        return dp[-1]
```