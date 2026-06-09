> 思路：对每一个位置i判断，如果$A[i]>max\{A[j],j=0,1,...,i-2\}$，则返回False。所以只需要维护一个Max变量即可。
```python
class Solution:
    def isIdealPermutation(self, A: List[int]) -> bool:
        
        if len(A) <= 2:
            return True
        
        Max = A[0]
        for i in range(2,len(A)):
            Max = max(Max,A[i-2])
            if A[i] < Max:
                return False
        return True
```