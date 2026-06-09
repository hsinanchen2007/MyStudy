### 解题思路
先把最大值找出来，再看最大值左边和右边是不是严格递减

### 代码

```python3
class Solution:
    def validMountainArray(self, A: List[int]) -> bool:
        if len(A) < 3:
            return False
        mx = max(A)
        index = A.index(mx)
        if index == 0:
            return False
        for i in range(index-1):
            if A[i] >= mx or A[i] >= A[i+1]:
                return False
        for j in range(index+1, len(A)-1):
            if A[j] >= mx or A[j] <= A[j+1]:
                return False
        if A[index-1] >= mx or A[-1] >= mx:
            return False
        return True
            

        
```