### 代码

```python3
class Solution:
    def findNthDigit(self, n: int) -> int:
        num = 9  # 个数
        digit = 1  # 位数

        while n - num * digit  > 0:
            # 个数 * 位数 == 总数字个数
            n -= num * digit
            num *= 10
            digit += 1
        a, b = divmod(n - 1, digit)
        return int(str(10 ** (digit - 1) + a)[b])
```