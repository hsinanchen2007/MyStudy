class Solution:
    def numJewelsInStones(self, J: str, S: str) -> int:
        n = 0
        for i in J:
            a = S.split(i)
            n += len(a) - 1
        return n