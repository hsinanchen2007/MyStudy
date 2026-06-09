每次都重新排序
```
class Solution(object):
    def lastStoneWeight(self, stones):
        """
        :type stones: List[int]
        :rtype: int
        """
        stones.sort()
        while len(stones)>=2:
            if stones[-1]==stones[-2]:
                stones=stones[:len(stones)-2]
            else:
                new=abs(stones[-1]-stones[-2])
                stones=stones[:len(stones)-2]
                stones.append(new)
                stones.sort()
        if stones==[]:
            stones.append(0)
        return stones[0]
```
