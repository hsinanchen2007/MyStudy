26进制转10进制，不用用字典一一对应，只要用ascii码减去某个值就可以了，这里是减去64，因为A的ascii码是65.

```python
class Solution(object):
    def titleToNumber(self, s):
        """
        :type s: str
        :rtype: int
        """
        sum=0
        for i in range(len(s)):
            sum+=26**(len(s)-1-i)*(ord(s[i])-64)
        return sum
```

