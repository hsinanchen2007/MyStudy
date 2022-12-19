```
class Solution:
    def canThreePartsEqualSum(self, A: List[int]) -> bool:
        if sum(A) % 3 != 0:
            return False
        sumup = sum(A) // 3
        # print(sumup)
        cnt = 0
        for i in range(len(A)-1):
            cnt += A[i]
            if cnt == sumup:
                cnt = 0
                for j in range(i+1, len(A)-1):
                    cnt += A[j]
                    if cnt == sumup:
                        return True
        return False
```
