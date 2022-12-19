### DP
![image.png](https://pic.leetcode-cn.com/19bb19e7dd82ca2ba526bc0a822694f863b9102cee7aabded92cdd82f6dc82d7-image.png)
- 这个题目让我们求组成和为`n`的完全平方数的最少个数
- 用于DP思路解,我们还是先设定`dp[i]`为组成和为`i`的最少完全平方数的个数
- 因为`i = k*k + b`,所以能得出:
- `dp[i] = 1 + dp[i-k*k]`,这里需要着重的解释这个公式的含义:
- 因为我们设定的`dp[i]`为组成和的完全平方数的**最少个数**,等于当前的这个平方数加上其余的平方数的个数,上面公式的中的`1`代表的是个数1,指的是`k*k`这当前的平方数,而`dp[i-k*k]`指的则是剩余的平方数的个数
- 由于我们每次计算是先把以前的数的最小平方数目计算出来了,所以只需循环的更新最小的那个完全平方数就好了

### 代码

```python
class Solution(object):
    def numSquares(self, n):
        """
        :type n: int
        :rtype: int
        """
        dp = [0]*(n+1)
        for i in range(1,n+1):
            dp[i] = i
            j = 1
            while (i - j*j) >= 0:
                dp[i] = min(dp[i],dp[i-j*j]+1)
                j += 1
        return dp[-1]

```