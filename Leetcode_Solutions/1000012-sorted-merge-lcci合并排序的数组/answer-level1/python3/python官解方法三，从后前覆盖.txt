### 解题思路
官解法，还是从浅入深，挺好理解的。
如何利用已有空间，很巧妙，从后往前放就可以了。
因为A的空间，正好是非0 A 与 B 空间的和，一定能放的下。

### 代码

```python
class Solution:
    def merge(self, A: List[int], m: int, B: List[int], n: int) -> None:
        """
        Do not return anything, modify A in-place instead.
        """
        s = len(A)-1
        # 从后往前覆盖
        while m > 0 and n > 0:
            # 从后往前放入最大的数
            if A[m-1] > B[n-1]:
                A[s] = A[m-1]
                m -= 1
            else:
                A[s] = B[n-1]
                n -= 1
            s -= 1
        if n > m: A[:s+1] = B[:n-1+1] # B 有剩余
        return A




```