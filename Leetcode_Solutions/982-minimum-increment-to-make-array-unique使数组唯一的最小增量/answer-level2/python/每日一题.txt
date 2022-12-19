### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def minIncrementForUnique(self, A: List[int]) -> int:
        count = [0] * 80000
        for x in A:
            count[x] += 1
        
        ans = taken = 0
        for x in range(80000):
            if count[x] >= 2:
                taken += count[x] - 1
                ans -= x * (count[x] - 1)
            elif taken > 0 and count[x] == 0:
                taken -= 1
                ans += x
        
        return ans
```