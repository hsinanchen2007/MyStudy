### 解题思路
从后往前比较，使用两个指针指向两个数组中的当前比较元素。将两个元素中较大的一个放在A数组后面的位置。

### 代码

```python3
class Solution:
    def merge(self, A: List[int], m: int, B: List[int], n: int) -> None:
        """
        Do not return anything, modify A in-place instead.
        """
        k = n + m -1
        i = m - 1
        j = n - 1
        while i>=0 and j>=0:
            if A[i] > B[j]:
                A[k] = A[i]
                k -= 1
                i -= 1
            else:
                A[k] = B[j]
                k -= 1
                j -= 1
        while j>=0:
            A[k] = B[j]
            k -= 1
            j -= 1
```