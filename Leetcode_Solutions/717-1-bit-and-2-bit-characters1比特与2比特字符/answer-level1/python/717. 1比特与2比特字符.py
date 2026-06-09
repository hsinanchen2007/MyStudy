```
class Solution(object):
    def isOneBitCharacter(self, bits):
        """
        :type bits: List[int]
        :rtype: bool
        """
        j = 0
        while j < len(bits):
            if j == len(bits) - 1:# 说明0没有被组合
                return True
            if bits[j] == 1: # 遇到1即组合为2比特字符
                j += 1
            j += 1
        return False
```
