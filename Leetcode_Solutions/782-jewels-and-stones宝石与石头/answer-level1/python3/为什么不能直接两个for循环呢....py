class Solution:
    def numJewelsInStones(self, J: str, S: str) -> int:
        count = 0
        for i in J:
            for j in S:
                if i == j:
                    count += 1
        return count