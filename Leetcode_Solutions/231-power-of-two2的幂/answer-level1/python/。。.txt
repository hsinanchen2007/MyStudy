```
class Solution(object):
    def isPowerOfTwo(self, n):
        return bin(n)[2] == '1' and bin(n)[3:] == (len(bin(n)[3:]))*'0'
```
