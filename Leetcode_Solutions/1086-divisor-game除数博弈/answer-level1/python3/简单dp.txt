### 解题思路
dp从简单的n开始。dp[n]代表给定数为n时，先手成功是否取胜。
如dp[1]先手必败，dp[2]考虑先手可选的符合要求的数字，只有1。那么当先手选1时，对手面临的情况为2-1,也是1
已经知道dp[1]先手必败所以,dp[2]=True，即当给定数字为2时，并且先手可选择1时，必胜。
以此类推。

至于归纳法得出的结果：偶数先手必胜，奇数先手必败。一般是要有一定数量的例子才能确定。当我们知道算法后打印出来清晰可见。然而，考场上。。。。
都能pass啦，谁还去归纳

### 代码

```python3
class Solution:
    def divisorGame(self, N: int) -> bool:
        dp=[False]*(N+1)
        for n in range(2,N+1):
            for x in range(1,n):
                if n%x==0 and  dp[n-x]==False:
                    dp[n]=True
                    break
        return dp[N]
```