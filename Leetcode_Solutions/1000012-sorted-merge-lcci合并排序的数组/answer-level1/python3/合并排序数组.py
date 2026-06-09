### 解题思路
双指针分别指向两个数组末尾，不需要辅助空间

### 代码

```python3
class Solution:
    def merge(self, A: List[int], m: int, B: List[int], n: int) -> None:
        """
        Do not return anything, modify A in-place instead.
        """
        pa=m-1
        pb=n-1
        tail =m+n-1
        while pa>=0 or pb>=0:
            if pa==-1:
                A[tail]=B[pb]
                pb-=1
            elif pb==-1:
                A[tail]=A[pa]
                pa-=1
            elif A[pa]<=B[pb]:
                A[tail]=B[pb]
                pb-=1
            else:
                A[tail]=A[pa]
                pa-=1
            tail-=1
        return A
```