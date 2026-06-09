### 解题思路
我只会数字与字符串转化的方法，刚好用在这里。而且python对列表的操作天生适合反转。

### 代码

```python3
class Solution:
    def reverse(self, x: int) -> int:
        str_x = str(x)
        if str_x[0]!='-':
            str_x = str_x[::-1]
            y = int(str_x)
            if y > 2**31-1:return 0
            else: return y
        else:
            str_x = str_x[:0:-1]
            y = -int(str_x)
            if y < -2**31:return 0
            else: return y


```