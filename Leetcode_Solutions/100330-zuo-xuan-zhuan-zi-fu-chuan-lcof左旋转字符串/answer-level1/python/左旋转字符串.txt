### 解题思路
此处撰写解题思路

### 代码

```python
class Solution(object):
    def reverseLeftWords(self, s, n):
        """
        :type s: str
        :type n: int
        :rtype: str
        """
        s1 = "".join(reversed(s[:n]))
        s2 = "".join(reversed(s[n:]))
        s3 = "".join(reversed(s1 + s2))
        return s3
```