- 十进制 - 二进制: bin(十进制)
- 二进制 - 十进制: int('二进制string', 2)
```
class Solution(object):
    def findComplement(self, num):
        """
        :type num: int
        :rtype: int
        """
        L = map(lambda i: '1' if i == '0' else '0', list(bin(num))[2:])
        return int(''.join(L), 2)
```
