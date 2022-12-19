### 解题思路
暴力法：跟反转字符串一样，不过数字需要去判断首位是否为负，溢出的情况单独判断就好了

### 代码

```python3
class Solution:
    def reverse(self, x: int) -> int:
        if -10 < x < 10:
            return x
        if str(x)[0] != '-':
            reverse_str = str(x)[::-1]
            y = int(reverse_str)
        else:
            reverse_str = str(x)[:0:-1]
            y = -int(reverse_str)
        return y if -2147483648 < y < 2147483647 else 0
```