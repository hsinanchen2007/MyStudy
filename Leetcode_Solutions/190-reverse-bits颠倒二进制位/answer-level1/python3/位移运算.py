### 解题思路
注意对于负数，算术运算有溢出的风险。

### 代码

```python3
class Solution:
    def reverseBits(self, n: int) -> int:
        ans = 0
        for _ in range(32):
            ans = (ans<<1) | (n&1)
            n >>= 1
        return ans
```