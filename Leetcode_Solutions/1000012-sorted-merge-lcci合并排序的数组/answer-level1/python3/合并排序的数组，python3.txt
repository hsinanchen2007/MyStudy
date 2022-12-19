### 解题思路
先把A数组尾部的n个元素删掉
然后依次在A中插入B中的元素

### 代码

```python3
class Solution:
    def merge(self, A: List[int], m: int, B: List[int], n: int) -> None:
        """
        Do not return anything, modify A in-place instead.
        """
        while n:
            del A[-1]
            n -= 1
        i = 0
        while B:
            while i < len(A):
                if A[i] < B[0]:
                    i += 1
                else:
                    break
            A.insert(i, B.pop(0))
```