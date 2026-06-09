### 解题思路
A list 从索引m后的空间都是可以容纳B list的元素的，然后再sort一下。

### 代码

```python3
class Solution:
    def merge(self, A: List[int], m: int, B: List[int], n: int) -> None:
        """
        Do not return anything, modify A in-place instead.
        """
        A[m:] = B
        A.sort()
        return A
```