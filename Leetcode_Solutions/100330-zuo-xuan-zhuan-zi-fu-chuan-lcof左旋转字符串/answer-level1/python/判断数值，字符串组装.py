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
        if n==0:
            return s
        if n>0 and n<len(s):
            return s[n:]+s[0:n]
        else:
            return s
```