### 解题思路
1.1-27进位转化为0-26进位
2.b的范围是0-25
3.ASCII码 b+65是指A-Z的范围


### 代码

```python
class Solution(object):
    def convertToTitle(self, n):
        """
        :type n: int
        :rtype: str
        """
        s = ''
        t = n
        while t > 0:
            t = t-1
            a = t//26
            b = t%26
            s = s + chr(b+65)
            t = a
        return s[::-1] #最先获得的反转到最后
```