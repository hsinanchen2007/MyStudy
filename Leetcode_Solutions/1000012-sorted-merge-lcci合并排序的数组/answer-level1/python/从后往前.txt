### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def merge(self, A: List[int], m: int, B: List[int], n: int) -> None:
        """
        Do not return anything, modify A in-place instead.
        """
        i = m-1
        j = n-1
        index = m+n-1
        while j>=0 and i>=0:
            if A[i]>=B[j]:
                A[index]=A[i]    
                i = i-1
            elif A[i]<B[j]:
                A[index]=B[j]
                j = j-1
            index -= 1
        # print(A)
        # print(i,j)
        if j!=-1:
            A[:j+1]=B[:j+1]
        return A

```