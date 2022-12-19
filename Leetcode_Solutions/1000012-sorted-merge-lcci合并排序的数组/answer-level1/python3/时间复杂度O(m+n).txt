![截屏2020-03-0310.48.05.png](https://pic.leetcode-cn.com/21fe49e5adcf8b16debab95ea2722f6cacc82d0e994673d9d001c79d0712b665-%E6%88%AA%E5%B1%8F2020-03-0310.48.05.png)
### 解题思路
根据A 和 B递增有序，我们从后向前遍历A和B，每次将A和B的较大元素添加到A的末端
### 代码

```python3
class Solution:
    def merge(self, A: List[int], m: int, B: List[int], n: int) -> None:
        """
        Do not return anything, modify A in-place instead.
        """
        k = m+n-1
        i = m-1
        j = n-1

        while i>=0 and j>=0 and k>=0:
            if A[i] < B[j]:
                A[k] = B[j]
                j -= 1
            else:
                A[k] = A[i]
                i -= 1
            k -= 1

        while i>=0:
            A[k] = A[i]
            k -= 1
            i -= 1
        while j>=0:
            A[k] = B[j]
            k -= 1
            j -= 1
```