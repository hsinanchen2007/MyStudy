# 低效的递归。。。
```
class Solution:
    def isOneBitCharacter(self, bits):
        if bits == [1,0]:
            return False
        elif bits == [0]:
            return True
        else:
            if bits[0] == 1:
                return self.isOneBitCharacter(bits[2:])
            else:
                return self.isOneBitCharacter(bits[1:])
```
