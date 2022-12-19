### 解题思路
![image.png](https://pic.leetcode-cn.com/90f1c87c94d2f60dacc4b1886a24f304a8363444a7e466d5a2de2f80bb4a2b9e-image.png)

- OK啦,这是一个一维DP问题,着重的还是要找到状态转移方程,线面就开始了:
- 我们先从最简单的例子分析,下面是我简单的分析:
![image.png](https://pic.leetcode-cn.com/c1072b401c3771f365f33dab304ee01143d6ccd9e84c50dcfc498f6e9561f2d2-image.png)

- 根据简单的分析可以总结出规律,这里的`f(n)`代表了有`n`个节点时所能生成的二叉搜索树,总结下公式为:
- `f(n) = 2*f(0)*f(n-1) + 2*f(1)*f(n-1) + f(n//2)*f(n//2)`

### 代码

```python
class Solution(object):
    def numTrees(self, n):
        """
        :type n: int
        :rtype: int
        """
        dp = [1]*(n+1)
        
        for i in range(2,n+1):
            temp1 = i-1
            temp2 = 0
            res = 0
            while temp2 < temp1:
                res += 2 * dp[temp1] * dp[temp2]
                temp1 -= 1
                temp2 += 1
            if temp2 == temp1:
                res += dp[temp2]**2
            dp[i] = res

        return dp[-1]


















```