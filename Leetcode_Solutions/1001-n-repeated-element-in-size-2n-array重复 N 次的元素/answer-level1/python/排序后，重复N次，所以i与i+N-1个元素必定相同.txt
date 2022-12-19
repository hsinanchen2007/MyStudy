### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def repeatedNTimes(self, A: List[int]) -> int:
        #N = len(A)//2
        A.sort()
        for i in range(len(A)//2+1):
            if A[i] == A[i+len(A)//2-1]:
               return A[i]
        
```