### 解题思路
三个指针A数组原地排序方法

### 代码

```python3
class Solution:
    def merge(self, A: List[int], m: int, B: List[int], n: int) -> None:
        """
        Do not return anything, modify A in-place instead.
        """

        a_idx = m - 1
        b_idx = n - 1
        p = m + n - 1

        while b_idx >= 0:
            if a_idx < 0 or A[a_idx] <= B[b_idx]:
                A[p] = B[b_idx]
                b_idx -= 1
            else:
                A[p] = A[a_idx]
                a_idx -= 1
            p -= 1
        
        
```