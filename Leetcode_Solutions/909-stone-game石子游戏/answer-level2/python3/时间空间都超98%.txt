![image.png](https://pic.leetcode-cn.com/b9f605158b18491346ba5b8e206fee917af4851959c02d3816f068f54f770683-image.png)


class Solution:
    def leetcode877(self, piles):
        if len(piles):
            pre,later = max(piles),min(piles)
            return [pre,later]
        tmp_1 = piles[0] + self.leetcode877(piles[1:len(piles)])[1]
        tmp_2 = piles[-1] + self.leetcode877(piles[0:len(piles)-1])[1]
        if tmp_1 >= tmp_2:
            return [tmp_1,self.leetcode877(piles[1:len(piles)])[1]]
        else:
            return [tmp_2,self.leetcode877(piles[0:len(piles)-1])[1]]

    def stoneGame(self, piles: List[int]) -> bool:
        [pre,later] = self.leetcode877(piles)
        if pre > later:
            return True
        else:
            return False