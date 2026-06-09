```
class Solution:
    def isOneBitCharacter(self, bits: List[int]) -> bool:
        l = 0
        i = 0
        if bits[-1] != 0:
            return False
        else:
            if bits == [0]:
                return True
            while i < len(bits):
                if bits[i:i+2] not in [[1,0],[1,1]]:
                    i += 1
                else:
                    i += 2
                if i == len(bits) - 1:
                    return True
            return False

```
