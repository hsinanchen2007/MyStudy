### 解题思路
将整数转换成字符串，然后反转字符串，再处理负号和越界的情况

### 代码

```python
class Solution(object):
    def reverse(self, x):
        """
        :type x: int
        :rtype: int
        """
        s = str(x)
        s = s[::-1]
        if s[-1] == '-':
            x=int(s[:-1])
            x = -1 * x
            if x < -2 ** 31:
                x = 0
        else:
            x=int(s)
            if x > 2 ** 31:
                x = 0

        return x
```