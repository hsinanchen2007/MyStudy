### 解题思路
在字符串的第n+1位开始一直到该字符串的末尾的那一部分与前面的那一部分颠倒顺序。
截取函数解释：
s[n:]表示从第n+1位一直到末尾的字符串
s[:n]表示从首位一直到n位的字符串

### 代码

```python
class Solution(object):
    def reverseLeftWords(self, s, n):
        """
        :type s: str
        :type n: int
        :rtype: str
        """
        return s[n:]+s[:n]
```