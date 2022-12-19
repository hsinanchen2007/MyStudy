暴力循环两次
```
class Solution:
    def twoSumLessThanK(self, A: List[int], K: int) -> int:
        n = len(A)
        res = -1
        for i in range(n):
            for j in range(i+1,n):
                sum_ = A[i]+A[j]
                if sum_<K:
                    res = max(res,sum_)
        return res
```
