```
class Solution(object):
    def longestArithSeqLength(self, A):
        """
        :type A: List[int]
        :rtype: int
        """
        res = 1
        resl = 0
        m = [{} for i in range(len(A)) ]
        for i in range(1, len(A)):
            for j in range(0, i):
                l = A[i]-A[j]
                m[i][l] = 1 + m[j].get(l, 1)
                res = max(m[i][l], res)
                resl = l
        return res
```
