### 解题思路
将B中元素逐个加到A列表末尾，然后用sort函数迅速得出结果

### 代码

```python3
class Solution:
    def merge(self, A: List[int], m: int, B: List[int], n: int) -> None:
        """
        Do not return anything, modify A in-place instead.
        """
        for i in range(n):
            A[m + i] = B[i] 
        return A.sort()
```