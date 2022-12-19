此题思路与 剪绳子I 完全相同，这里可当作 完全背包问题 处理。

dp[j] 表示长度为j的绳子，乘积的最大值
背包容量为n
注意：dp[0] = 1，因为求乘积的最大值，当i==j时，dp[0]要等于1

```
class Solution:
    def cuttingRope(self, n: int) -> int:
        dp = [0] * (n+1)
        dp[0] = 1

        for i in range(1, n): #注意这里是n 不是n+1
            for j in range(i, n+1):
                dp[j] = max(dp[j], dp[j-i]*i)
        
        return dp[n] % int(1e9+7)
```
![image.png](https://pic.leetcode-cn.com/ac77db7f908ed3a477bab981f20c4fcf5d43f2ff9e3cf0b4e53fe78d9df90af6-image.png)


注：i范围可缩小至1 ~ (n+1)//2
