
```
class Solution(object):
    def titleToNumber(self, s):
        """
        :type s: str
        :rtype: int
        """
        s=s[::-1]
        sum=0
        for index,v in enumerate(s):
            sum+=((ord(v)-64)*26**index)
        return sum
```