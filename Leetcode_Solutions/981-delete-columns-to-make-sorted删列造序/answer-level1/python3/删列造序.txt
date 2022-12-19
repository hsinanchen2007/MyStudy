### 解题思路
可以说是贪婪算法了，就直接统计就可以。
时间：o(N)
空间：o(1)
### 代码

```python3
class Solution:
    def minDeletionSize(self, A: List[str]) -> int:
        len_A = len(A)
        len_a = len(A[0])
        counts = 0
        for j in range(len_a):
            for i in range(len_A-1):
                if A[i][j] > A[i+1][j]:
                    counts += 1
                    break
        return counts

```