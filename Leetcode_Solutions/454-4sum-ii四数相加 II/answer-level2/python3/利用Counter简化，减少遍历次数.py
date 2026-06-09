```
import collections

class Solution:
    def fourSumCount(self, A: List[int], B: List[int], C: List[int], D: List[int]) -> int:
        A = collections.Counter(A)
        B = collections.Counter(B)
        C = collections.Counter(C)
        D = collections.Counter(D)
        AB = {}
        for ka in A:
            for kb in B:
                kab = ka + kb
                if kab not in AB:
                    AB[kab] = A[ka]*B[kb]
                else:
                    AB[kab] += A[ka]*B[kb]
        result = 0
        for kc in C:
            for kd in D:
                kab = - kc - kd
                if AB.get(kab):
                    # 已经记过数，用乘法
                    result += C[kc]*D[kd]*AB[kab]
        return result
```
用时212ms，超过99%
