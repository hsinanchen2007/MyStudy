```
class Solution:
    def isOneBitCharacter(self, bits: List[int]) -> bool:
        def _helper(bs):
            if bs in [[1, 0], [1, 1], [0], [0, 0]]:
                return True
            elif bs in [[1], [0,1]]:
                return False
            elif len(bs) >= 3:
                if bs[0] == 0:
                    return _helper(bs[1:])
                if bs[0] == 1:
                    return _helper(bs[2:])
                    
        if len(bits) == 1:
            return bits[0] == 0
        
        return _helper(bits[:-1])

```
