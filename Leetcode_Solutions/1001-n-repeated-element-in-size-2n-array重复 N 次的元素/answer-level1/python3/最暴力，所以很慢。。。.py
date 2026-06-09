```
class Solution:
    def repeatedNTimes(self, A: List[int]) -> int:
        count=0
        for i in A:
            count=A.count(i)
            if count==len(A)//2:
                return i
```
