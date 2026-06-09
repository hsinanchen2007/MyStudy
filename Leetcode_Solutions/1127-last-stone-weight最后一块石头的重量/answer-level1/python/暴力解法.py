class Solution(object):
    def lastStoneWeight(self, stones):
        """
        :type stones: List[int]
        :rtype: int
        """
        while len(stones)>1:
            a=max(stones)
            stones.remove(a)
            b=max(stones)
            stones.remove(b)
            if a!=b:
                stones.append(a-b)
            self.lastStoneWeight(stones)   
        if len(stones)==0:
            return 0
        if len(stones)==1:
            return stones[0]