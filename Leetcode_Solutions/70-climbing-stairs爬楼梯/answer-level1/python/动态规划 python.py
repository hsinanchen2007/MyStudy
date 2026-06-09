### 解题思路
假设我们现在站在台阶n上面，如何到达的n，有两种可能：

从第n-1台阶，一步走到了台阶n；
从第n-2台阶，两步走到了台阶n。

设函数f(n)为到达台阶n的所有可能的方法数量。则有
f(n) = f(n-1) + f(n-2)
即到达n的方法数等于到达n−1的方法数加上到达n−2的方法数。

大的问题依赖小的问题，这就是最基本的动态规划的原则。


### 代码

```python3
class Solution:
    def climbStairs(self, n: int) -> int:
        ### 动态规划
        dp = [0,1,2]

        for i in range(3,n+1):
            dp.append(dp[i-1]+dp[i-2])
        return dp[n]
```