```
代码块
class Solution(objects):
    def lastStoneWeight(self,stones):
        """
        :type stones: List[int]
        :rtype: int
        """
        while len(stones)>1:
            Max1=max(stones)
            Index1=stones.index(Max1)
            stones.pop(Index1)

            Max2=max(stones)
            Index2=stones.index(Max2)
            stones.pop(Index2)
            if Max1>Max2:
                stones.append(Max1-Max2)
        if len(stones)==0:
            return 0
        else:
            return stones[0]

```
