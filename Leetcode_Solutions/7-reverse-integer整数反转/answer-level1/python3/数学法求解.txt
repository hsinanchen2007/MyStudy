### 解题思路
先取输入数的绝对值，然后利用对10取余法求得反转后的数。
最后判断结果是否在存储空间，如果不在，返回0.
最后根据输入数是正数还是负数还返回值。

根据结果，比利用字符串法速度更慢。

### 代码

```python3
class Solution:
    def reverse(self, x: int) -> int:
        value = abs(x)
        result = 0
        while value != 0:
            digit = value % 10
            value //= 10
            result = result * 10 + digit
        if result < -2**31 or result > 2**31-1:
            return 0
        if x > 0:
            return result
        elif x < 0:
            return -result
        else:
            return 0



```