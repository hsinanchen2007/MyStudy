### 解题思路

原地从后向前遍历，不需要额外空间，

### 代码

```
class Solution:
    def merge(self, A: List[int], m: int, B: List[int], n: int) -> None:
        """
        Do not return anything, modify A in-place instead.
        """
        cur = -1
        p_1 = m-1
        p_2 = n-1
        if m==0:
            A[:]= B
        
        
        while(p_1>-1 and p_2>-1):
            if A[p_1]<B[p_2]:
                A[cur] =B[p_2]
                p_2-=1
                cur-=1
                
            else:
                A[cur] =A[p_1]
                p_1-=1
                cur-=1
        
        while p_2>-1:
            A[cur] = B[p_2]
            cur-=1
            p_2-=1
        


            


```