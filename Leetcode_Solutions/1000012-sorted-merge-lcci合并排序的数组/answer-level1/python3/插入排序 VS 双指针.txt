**插入排序，双指针**
每次插入，都要从后往前移动后面的元素，给插入的元素腾位置。
当双指针相遇，把B剩下的元素放在A后面即可。

时间复杂度=O((m+n) * m)
空间复杂度=O(1)

```python3
class Solution:
    def merge(self, A: List[int], m: int, B: List[int], n: int) -> None:
        """
        Do not return anything, modify A in-place instead.
        """
        pa = pb = 0
        while pb < n and pa < m+n:
            if B[pb] < A[pa]:
                for j in range(m+pb, pa, -1):
                    A[j] = A[j-1]
                A[pa] = B[pb]
                pb += 1
            elif pa == m + pb:
                A[pa:] = B[pb:]
                pb = n
            pa += 1
```

**逆序三指针**
从后往前遍历，每次取两者中较大的置于A的尾侧。

时间复杂度=O(m+n)
空间复杂度=O(1)

```python3
class Solution:
    def merge(self, A: List[int], m: int, B: List[int], n: int) -> None:
        """
        Do not return anything, modify A in-place instead.
        """
        pa = m - 1
        pb = n - 1
        tail = m + n -1
        while pa >= 0 or pb >= 0:
            if pa == - 1:
                A[tail] = B[pb]
                pb -= 1
            elif pb == -1:
                A[tail] = A[pa]
                pa -= 1
            elif B[pb] > A[pa]:
                A[tail] = B[pb]
                pb -= 1
            else:
                A[tail] = A[pa]
                pa -= 1
            tail -= 1
```