### 解题思路

### 代码

```python3
class Solution:
    def minIncrementForUnique(self, A: List[int]) -> int:
        count = [0] * 80000
        for i in A:
            count[i] += 1
        ans = taken = 0
        for j in range(80000):
            if count[j] >= 2:
                taken += count[j] -1
                ans -= j * (count[j] - 1)
            elif taken > 0 and count[j] == 0:
                taken -= 1
                ans += j
        return ans
```