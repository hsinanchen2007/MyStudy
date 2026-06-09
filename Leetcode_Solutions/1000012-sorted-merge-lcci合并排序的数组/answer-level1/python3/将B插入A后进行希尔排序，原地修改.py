### 解题思路：
首先需要想到的是先把B加到A预留的缓存空间里。因为A、B的元素个数都给了，所以我想到是直接遍历B，然后依次加到A的缓存空间中：
```python
        for x in B:
            A[m] = x
            m += 1
```
然后就是排序了，由于需要直接在A上面修改，不返回，所以用了**希尔排序**：
```python
        # 希尔排序
        len_A = len(A)
        # 取间隔值，直接取对半好理解
        gap = len_A // 2
        while gap > 0:
            # 从gap到len_A中，对每相邻gap间隔的元素进行插入排序
            for i in range(gap, len_A):
                j = i
                current = A[i]
                # 当相邻gap的前一个元素比当前元素大时，则交换
                while j - gap >= 0 and current < A[j - gap]:
                    A[j] = A[j - gap]
                    j -= gap
                A[j] = current
            # 然后再取新的gap值
            gap //= 2
```

### 完整代码：
```python
class Solution:
    def merge(self, A: List[int], m: int, B: List[int], n: int) -> None:
        """
        Do not return anything, modify A in-place instead.
        """
        for x in B:
            A[m] = x
            m += 1
        # 希尔排序
        len_A = len(A)
        # 取间隔值，直接取对半好理解
        gap = len_A // 2
        while gap > 0:
            # 从gap到len_A中，对每相邻gap间隔的元素进行插入排序
            for i in range(gap, len_A):
                j = i
                current = A[i]
                # 当相邻gap的前一个元素比当前元素大时，则交换
                while j - gap >= 0 and current < A[j - gap]:
                    A[j] = A[j - gap]
                    j -= gap
                A[j] = current
            # 然后再取新的gap值
            gap //= 2
```


