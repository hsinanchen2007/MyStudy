```
class Solution:
    def sortArrayByParityII(self, A: List[int]) -> List[int]:
        oushu = [i for i in A if i % 2 ==0]
        jishu = [i for i in A if i % 2 ==1]
        new_A = [0]*len(A)
        j = 0
        for i in oushu:
            new_A[j]=i
            j+=2
        j = 1
        for i in jishu:
            new_A[j]=i
            j+=2
        return new_A
```
