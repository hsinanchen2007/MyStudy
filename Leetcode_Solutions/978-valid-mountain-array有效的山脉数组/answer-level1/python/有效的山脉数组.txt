### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def validMountainArray(self, A: List[int]) -> bool:
        # 原作者：leetCode-Solution
        N = len(A)
        i = 0

        # walk up
        while i+1 < N and A[i] < A[i+1]:
            i += 1

        # peak can't be first or last
        if i == 0 or i == N-1:
            return False

        # walk down
        while i+1 < N and A[i] > A[i+1]:
            i += 1

        return i == N-1


        # 会超时
        # length = len(A)
        # if length < 3:
        #     return False
        
        # for i in range(1,length-1):
        #     if all(A[k]<A[k+1] for k in range(i)) and all(A[m] > A[m+1] for m in range(i,length-1)):
        #         return True
        # return False

        
            
```