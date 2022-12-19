### 解题思路
从后面开始遍历 双指针

### 代码

```python
class Solution(object):
    def merge(self, A, m, B, n):
        p1 = m - 1
        p2 = n - 1
        p = m + n - 1
        while p1 >= 0 and p2 >= 0:
            if A[p1] < B[p2]:
                A[p] = B[p2]
                p2 -= 1
            else:
                A[p] = A[p1]
                p1 -= 1
            p -= 1
        A[:p2 + 1] = B[:p2 + 1]
        return 
```