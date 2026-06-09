### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def merge(self, A: List[int], m: int, B: List[int], n: int) -> None:
        """
        Do not return anything, modify A in-place instead.
        """
        #双指针
        C = []
        a = 0
        b = 0
        while a<m or b< n:
            if a==m:
                C.append(B[b])
                b+=1
            elif b==n:
                C.append(A[a])
                a+=1
            elif A[a]<B[b]:
                C.append(A[a])
                a+=1
            else:
                C.append(B[b])
                b+=1
        A[:] = C




        # #B放进A内再排序
        # A[m:] = B
        # A.sort()
```