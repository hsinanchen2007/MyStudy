```
# https://leetcode-cn.com/problems/maximize-sum-of-array-after-k-negations/
class Solution:
    def largestSumAfterKNegations(self, A: List[int], K: int) -> int:
        while True:
            if K == 0:
                return sum(A)
            A = sorted(A)
            if A[0] < 0:
                A[0] = -A[0]
                K -= 1
            elif K % 2 == 1:
                A[0] = -A[0]
                K = 0
            else:
                return sum(A)

```
