```
class Solution:
    def numSubarraysWithSum(self, A: List[int], S: int) -> int:
        d = {0:1}
        count = 0
        sum1 = 0
        for i in range(len(A)):
            sum1 += A[i]
            if sum1-S  in d:
                count+=d[sum1-S]
            if sum1 not in d:
                d[sum1] = 1
            else:
                d[sum1]+=1
        return count
        
            
        
```
