```
class Solution:
    def lastStoneWeight(self, stones: List[int]) -> int:
        stones.sort()
        n1 = len(stones)
        if n1 == 1:
            return(stones[0])
        #stones.reverse()
        while len(stones) > 1:
            num = stones[-1] - stones[-2]
            stones.pop()
            stones.pop()
            if num == 0:
                pass
            else:
                stones.append(num)
            stones.sort()
        if len(stones) == 1:
            return(stones[0])
        else:
            return(0)
```
