import copy
class Solution:
    def commonChars(self, A: List[str]) -> List[str]:
        c = list(A[0])
        for a in A[1:]:
            a = list(a)
            d = copy.copy(c)
            for i in d:
                try:
                    a.remove(i)
                except:
                    c.remove(i)
        return c