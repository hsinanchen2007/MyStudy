class Solution:
    def numEquivDominoPairs(self, dominoes: List[List[int]]) -> int:
        a = 0
        b = dict()
        for b1,b2 in dominoes:
            index = tuple(sorted((b1, b2)))
            if index in b:
                b[index] += 1
            else:
                b[index] = 1
        for i in b:
            a += b[i] * (b[i] - 1) // 2
        return a