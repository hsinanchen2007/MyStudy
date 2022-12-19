### 解题思路
将数字转化成字符串，通过切片倒置。再转化成数字。

### 代码

```python
class Solution(object):
    def reverse(self, x):
        """
        :type x: int
        :rtype: int
        """
        a=str(x)
        if '-' in a:
            a=0-int(a[1:][::-1])
            if a<(-2**31):
                return 0
            else:
                return a
        else:
            a = int(a[::-1])
            if a>2**31-1:
                return 0
            else:
                return a
```