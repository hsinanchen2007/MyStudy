### 解题思路
三次旋转法

### 代码

```python
class Solution(object):
    def reverseLeftWords(self, s, n):
        """
        :type s: str
        :type n: int
        :rtype: str
        """
        if n > len(s) or not s:
            return ''
        s = list(s)
        def reverse(start, end):
            while start < end:
                s[start], s[end] = s[end], s[start]
                start += 1
                end -= 1
        length = len(s) - 1
        reverse(0, n-1)
        reverse(n,length)
        reverse(0, length)
        return ''.join(s)
```