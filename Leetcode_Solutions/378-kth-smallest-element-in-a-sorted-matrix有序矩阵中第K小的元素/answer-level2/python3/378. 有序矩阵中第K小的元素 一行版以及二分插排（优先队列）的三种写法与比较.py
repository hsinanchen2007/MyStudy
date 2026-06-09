第一种纯插排我以为最慢，结果最快，550ms左右，第二种维护K长度的优先队列，我以为最快结果表现一般，1200m左右，我以为慢在pop()这个点上，在一二基础上改进了一下，结果2500ms左右，刚好各翻一倍，然后我仏了，干脆直接解包系统快排输出拉到了，结果果然比第一种快，才260ms左右，正好又是第一种的一半时间，估计慢都慢在插入这个操作上了。

二分插排，不维护长度，每次插入为O(logn)：

```py
class Solution:
    def kthSmallest(self, matrix: List[List[int]], k: int) -> int:
        q = []
        for mat in matrix:
            for i in mat:
                bisect.insort(q, i)
        return q[k - 1]
```

二分插排，维护长度，每次插入为O(logk)：

```py
class Solution:
    def kthSmallest(self, matrix: List[List[int]], k: int) -> int:
        q = [float('inf')] * k
        for mat in matrix:
            for i in mat:
                bisect.insort(q, i, hi = k)
                q.pop()
        return q[-1]
```
二分插排，不维护长度，每次插入O(logk)：

```py
class Solution:
    def kthSmallest(self, matrix: List[List[int]], k: int) -> int:
        q = [float('inf')] * k
        for mat in matrix:
            for i in mat:
                bisect.insort(q, i, hi = k)
        return q[k - 1]
```

一行版，先把二维数组解包成一维数组，然后系统快排，整体O(nlogn)，但没有插入操作，全是交换操作，所以可能比较快：

```py
class Solution:
    def kthSmallest(self, matrix: List[List[int]], k: int) -> int:
        return sorted([*itertools.chain(*matrix)])[k - 1]
```
```py
[*itertools.chain(*matrix)]
相当于：
[matrix[i][j] for j in range(len(matrix[0])) for i in range(len(matrix))]
```
