```
class Solution(object):
    def addBinary(self, a, b):
        """
        :type a: str
        :type b: str
        :rtype: str
        """
        i = 0
        c = 0
        res = ''
        while i<len(a) or i<len(b) or c:
            a1 = a[len(a) -1 -i] if i<len(a) else 0
            b1 = b[len(b) -1 -i] if i<len(b) else 0
            n = int(a1) + int(b1) + c
            res = str(n % 2) + res
            c = n//2
            i += 1
        return res

```
