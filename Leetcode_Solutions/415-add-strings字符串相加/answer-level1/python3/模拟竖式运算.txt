```
class Solution(object):
    def addStrings(self, num1, num2):
        """
        :type num1: str
        :type num2: str
        :rtype: str
        """
        c = 0
        res = ''
        i, j = len(num1)-1, len(num2)-1
        while i>=0 or j>=0 or c:
            n = int(num1[i]) if i>=0 else 0
            n += int(num2[j]) if j>=0 else 0
            n += c
            c, n = n//10, n%10
            res = str(n) + res
            i -= 1
            j -= 1
        return res
```
