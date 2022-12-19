### 解题思路
利用组成来做,就是暴力穷举.让我没想到的是执行时间(524ms)会比动态规划快那么多

### 代码

```python3
from itertools import combinations_with_replacement
class Solution:
    def numSquares(self, n: int) -> int:
        if n < 4:
            return n
        nums = [i**2 for i in range(1, int(n**0.5)+2)]
        if n in nums:
            return 1
        for j in range(2, len(nums)+2):
            for i in combinations_with_replacement(nums, j):
                if sum(i) == n:
                    return j
```