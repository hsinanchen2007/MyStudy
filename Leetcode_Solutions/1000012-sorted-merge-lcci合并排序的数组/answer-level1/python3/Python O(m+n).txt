### 解题思路
创建一个list来存放新的数列，最后赋值到A上去

### 代码

```python3
class Solution:
    def merge(self, A: List[int], m: int, B: List[int], n: int) -> None:
        """
        Do not return anything, modify A in-place instead.
        """
        a = 0
        b = 0
        new_A = []
        while a < m or b < n:
            if a == m:
                new_A.append(B[b])
                b += 1
            elif b == n:
                new_A.append(A[a])
                a += 1
            elif A[a] < B[b]:
                new_A.append(A[a])
                a += 1
            elif A[a] >= B[b]:
                new_A.append(B[b])
                b += 1
        A[:] = new_A
```