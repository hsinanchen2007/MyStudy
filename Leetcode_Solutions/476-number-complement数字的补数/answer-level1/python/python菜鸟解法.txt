```
class Solution(object):
    def findComplement(self, num):
        """
        :type num: int
        :rtype: int
        """
        return int(bin(num).replace('0b', '').replace("0", "2").replace("1", "0").replace("2", "1"), 2)
```
