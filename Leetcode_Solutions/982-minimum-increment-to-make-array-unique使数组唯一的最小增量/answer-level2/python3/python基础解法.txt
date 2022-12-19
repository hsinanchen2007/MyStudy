### 解题思路
使用排序加贪心算法来解决问题。先排序，这样贪心算法就能得到全局最优解了

### 代码

```python3
class Solution:
    def minIncrementForUnique(self, A: List[int]) -> int:
        A.sort()
        count = 0
        for i in range(1, len(A)):
            if A[i] <= A[i-1]:
                count += A[i-1] - A[i] + 1
                A[i] = A[i-1] + 1
        return count
```