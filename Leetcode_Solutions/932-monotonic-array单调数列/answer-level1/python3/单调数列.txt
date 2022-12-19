### 解题思路
all()的用法，但内存占用较大

### 代码

```python3
class Solution:
    def isMonotonic(self, A: List[int]) -> bool:
        if len(A) < 2 or len(set(A)) == 1:
            return True

        # for i in range(len(A) -1):
        #     for j in range(i+1,len(A)):
        #         if 
        asen = all(A[i] <= A[i+1] for i in range(len(A)-1))
        
        des = all(A[i] >= A[i+1] for i in range(len(A)-1))

        if asen or des:
            return True
        else:
            False
        
        
```