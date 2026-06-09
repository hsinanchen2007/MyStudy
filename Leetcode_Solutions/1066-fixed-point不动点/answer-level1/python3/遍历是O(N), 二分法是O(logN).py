```
class Solution:
    def fixedPoint(self, A: List[int]) -> int:
        # 1. 0(n), no more explanation
        # for i in range(len(A)):
        #     if i == A[i]:
        #         return i
        # return -1
    
        # 2. O(logN), this is what interviewer want!
        left, right = 0, len(A) - 1
        while left < right:
            mid = (left+right) // 2
            if A[mid] >= mid:
                right = mid
            else:
                left = mid+1
        return left if A[left] == left else -1
```
因为题目中说了`distinct`, 且A是升序. 所以如果有fiexed point的话就一定只有一个.