### 代码

```python3
class Solution:
    def maxA(self, N: int) -> int:
        # 最后一次按键要么是 A 要么是 C-V
        # 定义：dp[i] 表示 i 次操作后最多能显示多少个 A
        dp = [0] * (N + 1)
        for i in range(1, N + 1):
            # 按A键
            dp[i] = dp[i - 1] + 1
            for j in range(2, i):
                # 全选 & 复制 dp[j-2]，连续粘贴 i - j 次
                # j 之前的 2 个操作是 C-A C-C
                # 屏幕上共 dp[j - 2] * (i - j + 1) 个 A
                dp[i] = max(dp[i], dp[j - 2] * (i - j + 1))
        return dp[N]
```