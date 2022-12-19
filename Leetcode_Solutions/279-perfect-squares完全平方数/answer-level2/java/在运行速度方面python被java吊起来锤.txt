同样的代码？？
![TIM图片20191225161203.png](https://pic.leetcode-cn.com/6f14cc9779e94dbe68ed327ba24592a1643901f97d49beca9ac6252ac9531244-TIM%E5%9B%BE%E7%89%8720191225161203.png)

python这么慢！

```
class Solution:
    def numSquares(self, n: int) -> int:
        if n <= 3:
            return n
        dp = [sys.maxsize] * (n + 1)
        for i in range(1, 4):
            dp[i] = i
        for i in range(4, n + 1):
            max_n = int(math.sqrt(i))
            if max_n * max_n == i:
                dp[i] = 1
            else:
                for j in range(1, max_n + 1):
                    dp[i] = min(dp[i], dp[i - j * j] + dp[j*j])
        return dp[-1]
```
