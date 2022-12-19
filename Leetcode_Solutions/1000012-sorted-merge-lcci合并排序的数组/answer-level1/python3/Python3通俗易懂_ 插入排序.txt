### 解题思路
这题就是复习一下插入排序(***插牌).
插入排序要点: 元素从后往前遍历, 不断把原有序列中的元素往后调整, 直到e > A[i]
循环结束后, 把A[i + 1]设置为待插入元素.
### 代码

```python3
class Solution:
    def merge(self, A: List[int], m: int, B: List[int], n: int) -> None:
        """
        Do not return anything, modify A in-place instead.
        """
        for e in B:
            A[m] = e
            i = m - 1
            while i >= 0 and e < A[i]:
                A[i + 1] = A[i]
                i -= 1
            A[i + 1] = e
            m += 1
```