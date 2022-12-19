
```
class Solution(object):
    def titleToNumber(self, s):
        """
        :type s: str
        :rtype: int
        """
        result = 0
        for i,x in enumerate(s[::-1]): # 
            result += (ord(x)-64)*26**(i)
        return result
            
```
