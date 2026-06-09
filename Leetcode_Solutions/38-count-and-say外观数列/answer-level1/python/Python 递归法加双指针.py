```
class Solution(object):
    def countAndSay(self, n):
        """
        :type n: int
        :rtype: str
        """
        if n == 1:
            return '1'

        s = self.countAndSay(n-1)
        start, end = 0, 0
        ret = ''
        while end < len(s):
            if s[end] != s[start]:
               ret = ret + str(end-start) + s[start]
               start = end
            end += 1

        ret = ret + str(end-start) + s[start]
        
        return ret
```
