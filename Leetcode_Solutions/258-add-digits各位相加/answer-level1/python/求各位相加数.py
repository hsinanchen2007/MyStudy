### 解题思路
简单的思路

### 代码

```python3
class Solution:
    def addDigits(self, num: int) -> int:
        a, b = divmod(num, 10)
        while a:
            num = b
            while a:
                num += a % 10
                a //= 10
            a, b = divmod(num, 10)
        return b

```