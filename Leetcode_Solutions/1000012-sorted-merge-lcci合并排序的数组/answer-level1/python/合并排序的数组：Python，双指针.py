### 解题思路
每次从A,B数组头部取出较小的数放入新数组rlist，当A数组循环完毕后，将B数组剩余部分直接连接到rlist尾部，反之亦然，最后改变A数组值为rlist。

### 代码

```python
class Solution(object):
    def merge(self, A, m, B, n):
        """
        :type A: List[int]
        :type m: int
        :type B: List[int]
        :type n: int
        :rtype: None Do not return anything, modify A in-place instead.
        """
        rlist = []
        i, j = 0, 0
        while (i < m and j < n):
            if A[i] < B[j]:
                rlist.append(A[i])
                i += 1
            elif A[i] > B[j]:
                rlist.append(B[j])
                j += 1
            else:
                rlist.append(A[i])
                i += 1
                rlist.append(B[j])
                j += 1
        if i == m:
            rlist.extend(B[j:])
        elif j == n:
            rlist.extend(A[i:m])
        A[:] = rlist
        return A
```