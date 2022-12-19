####完成任务，请转道

### 解题思路
方法一：直肠子
合并数组，然后排序
契合题意，但是Python这种偷鸡的行为不具有复制性，不过这也是学习Python的原因

时间复杂度：O((m+n)log(m+n))
空间复杂度：O(log(m+n))

### 代码

```python3
class Solution:
    def merge(self, A: List[int], m: int, B: List[int], n: int) -> None:
        """
        Do not return anything, modify A in-place instead.
        """
        A[m:]=B
        A.sort()
```

### 解题思路
方法二：双指针
建议参观官方解释，动图非常棒
#不契合题意
尝试了for和zip并不能错位遍历
时空复杂度：O(m+n)

### 代码
```python3
class Solution:
    def merge(self, A: List[int], m: int, B: List[int], n: int) -> None:
        """
        Do not return anything, modify A in-place instead.
        """
        sorted = []
        pa, pb = 0, 0
        while pa < m or pb < n:
            if pa == m:
                sorted.append(B[pb])
                pb += 1
            elif pb == n:
                sorted.append(A[pa])
                pa += 1
            elif A[pa] < B[pb]:
                sorted.append(A[pa])
                pa += 1
            else:
                sorted.append(B[pb])
                pb += 1
        A[:] = sorted
```

### 解题思路
方法三：双指针强化版
事实上这个才是最符合题意的，充分利用了已知的缓存区

### 代码
```python3
class Solution:
    def merge(self, A: List[int], m: int, B: List[int], n: int) -> None:
        """
        Do not return anything, modify A in-place instead.
        """
        pa, pb = m - 1, n - 1
        tail = m + n - 1
        while pa >= 0 or pb >= 0:
            if pa == -1:
                A[tail] = B[pb]
                pb -= 1
            elif pb == -1:
                A[tail] = A[pa]
                pa -= 1
            elif A[pa] > B[pb]:
                A[tail] = A[pa]
                pa -= 1
            else:
                A[tail] = B[pb]
                pb -= 1
            tail -= 1
```