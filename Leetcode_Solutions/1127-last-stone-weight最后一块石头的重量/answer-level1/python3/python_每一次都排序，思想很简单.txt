```
class Solution:
    def lastStoneWeight(self, stones: list):
        while len(stones) > 1:
            stones.sort()
            if stones[-1] == stones[-2]:
                stones.pop(-1)
                stones.pop(-1)
            else:
                stones[-1] = stones[-1] - stones[-2]
                stones.pop(-2)
        if len(stones) != 0:
            return stones[0]
        else:
            return 0
```
