主要思路就是先从头到位遍历字符串s，每次从其后面的索引开始找是否出来该索引对应的字符 并且对其字符计数（'llllove' 不计数的话 会返回最后一个'l'的索引，而不是'o'的索引），同时满足则返回当前字符的索引，完成！

```python
class Solution(object):
    def firstUniqChar(self, s):
        """
        :type s: str
        :rtype: int
        """
        if not len(s):
            return -1
        for i in range(len(s)):
            if s.find(s[i],i+1) == -1 and s.count(s[i])==1:
                return i
        return -1
```