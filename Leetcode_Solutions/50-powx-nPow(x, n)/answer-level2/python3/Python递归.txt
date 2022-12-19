### 解题思路
递归--当除到0时退出

### 代码

```python3
class Solution:
    def myPow(self, x: float, n: int) -> float:
        if n < 0:
            n = -n
            x = 1 / x
            return self.dp(x, n)
        return self.dp(x, n)

    def dp(self, xx, nn):
        if nn == 0:
            return 1
        elif nn % 2 == 0:
            half = self.dp(xx, nn // 2)
            return half * half
        else:
            half = self.dp(xx, (nn - 1) // 2)
            return half * half * xx
```