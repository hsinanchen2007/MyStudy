以为会超时，试着提交了一下，居然过了(￣▽￣)"
```
class Solution:
    def canThreePartsEqualSum(self, A: List[int]) -> bool:
        sum_A = sum(A)
        if sum_A%3 != 0:
            return False
        d = sum_A//3
        s = 0
        count = 0
        for i in range(len(A)):
            s += A[i]
            if s == d:
               count += 1
               s = 0
        return count == 3
```
