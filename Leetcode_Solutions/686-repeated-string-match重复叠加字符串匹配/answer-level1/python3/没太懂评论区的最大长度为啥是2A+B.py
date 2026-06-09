class Solution:
    def repeatedStringMatch(self, A: str, B: str) -> int:
        res = 1
        a= A
        while len(a) <= 10000:
            if B in a:
                return res
            else:
                a = A
                res += 1
                a = a * res
        return -1