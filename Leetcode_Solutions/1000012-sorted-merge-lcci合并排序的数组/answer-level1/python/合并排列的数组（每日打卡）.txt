### 解题思路
已知A有足够的空间以及A,B的长度，那么从A,B的末位元素从后往前开始比较并插入到对应位置。

### 代码

```python3
class Solution:
    def merge(self, A: List[int], m: int, B: List[int], n: int) -> None:
        """
        Do not return anything, modify A in-place instead.
        """
        pa = m-1
        pb = n-1
        last = m + n - 1
        while pa >= 0 and pb >= 0:   
            if A[pa] > B[pb]:
                A[last] = A[pa]
                pa -= 1
            else:
                A[last] = B[pb]
                pb -= 1
            last -= 1
        if pa < 0:
            A[:pb + 1] = B[:pb + 1]
 
            
            

```