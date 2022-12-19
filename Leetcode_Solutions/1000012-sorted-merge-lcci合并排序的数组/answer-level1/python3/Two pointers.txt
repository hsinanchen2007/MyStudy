贴个代码吧.
一开始循环条件并没有设置为`B`的指针,即`b`,而是设为了`cur`, 即游走指针.
这么写虽然没错, 但是造成了一个问题: 没有early stop, 当`b == -1`时程序在空跑.
```python
class Solution:
    def merge(self, A: List[int], m: int, B: List[int], n: int) -> None:
        """
        Do not return anything, modify A in-place instead.
        """

        # intersection
        a, b, cur = m - 1, n - 1, m + n - 1
        while b >= 0:
            if A[a] < B[b]:
                A[cur], b = B[b], b - 1
            elif a >= 0:
                A[cur], a = A[a], a - 1
            cur -= 1
```
