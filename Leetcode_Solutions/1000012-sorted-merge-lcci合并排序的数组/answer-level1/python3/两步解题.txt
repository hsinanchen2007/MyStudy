### 解题思路
把所有B中的元素附到 A 的后部，然后 remove 掉新 A中的n个0，再排序，就 OK。

### 代码

```python3
class Solution:
    def merge(self, A: List[int], m: int, B: List[int], n: int) -> None:
        """
        Do not return anything, modify A in-place instead.
        """
        for i in range(n):
            A.append(B[i])
        while n != 0:
            A.remove(0)
            n -= 1
        A.sort()
```