### 解题思路
rt
### 代码

```python3
class Solution:
    def reverse(self, x: int) -> int:
        if 10>x>-10:
            return x
        str_x = str(x)
        if str_x[0] != '-':
            str_x = str_x[::-1]
            x = int(str_x)
        else:
            str_x = str_x[:0:-1] # 当使用-1的时候，前面那位数就是后界，第二位就是前界
            x = int(str_x)
            x = -x
        return x if -2147483648 < x < 2147483647 else 0
```