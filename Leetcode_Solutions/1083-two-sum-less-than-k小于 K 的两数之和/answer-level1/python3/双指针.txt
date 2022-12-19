```
class Solution:
    def twoSumLessThanK(self, A: List[int], K: int) -> int:
        A, ret = sorted(A), -1
        while A[-1] > K:
            A.pop()
            
        p1, p2 = 0, len(A) - 1
        while p1 < p2:
            t = A[p1] + A[p2]
            if  t >= K:
                p2 -= 1
            else:
                if t > ret:
                    ret = t
                p1 += 1

        return max(-1, ret)
```
