### 题解
最初的想法肯定是再开一个列表，然后排好之后复制到A，这样多用了O(n+m)的空间
那么想法就来了，在尾部操作，就不需要额外空间了
### 代码

```python3
class Solution:
    def merge(self, A: List[int], m: int, B: List[int], n: int) -> None:
        """
        Do not return anything, modify A in-place instead.
        """
        p1=m-1
        p2=n-1
        for i in range(m+n-1,-1,-1):
            if p2<0:
                break
            if p1<0 or A[p1]<B[p2]:
                A[i] = B[p2]
                p2 -=1
            else:
                A[i] = A[p1]
                p1 -=1
```