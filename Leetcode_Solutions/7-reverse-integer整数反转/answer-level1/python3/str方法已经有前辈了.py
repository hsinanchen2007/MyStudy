### 解题思路
不过我还是减少下运行时间和内存消耗，20ms，12.7mb

### 代码

```python3
class Solution:
    def reverse(self, x: int) -> int:
        result = int(str(abs(x))[::-1])*(-1 if x < 0 else 1)
        return result if -2**31 <= result <= 2**31-1 else 0

```