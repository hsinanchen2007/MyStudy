转化成字符串，反转之后再转化回来。

整道题目的代码如下：

```python
class Solution(object):
    def reverse(self, x):
        """
        :type x: int
        :rtype: int
        """
        x = str(x)
        flag = False
        if x[0] == '-':
            x = x[1::]
            flag = True
        x = x[::-1]
        if flag:
            res = -int(x)
        else:
            res = int(x)
        minv = -(1 << 31)
        maxv = (1 << 31) - 1
        if res < minv or res > maxv:
            return 0
        return res
```

