### 解题思路
思路简单粗暴，用切片把A里为0的元素用B代替。然后这题要求原地，所以不能A = sorted(A)，用内置的.sort()就行

### 代码

```python3
class Solution:
    def merge(self, A: List[int], m: int, B: List[int], n: int) -> None:
        """
        Do not return anything, modify A in-place instead.
        """
        A[m:m+n] = B
        return A.sort()
```