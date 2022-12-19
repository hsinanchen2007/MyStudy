### 解题思路
排列组合真好用

### 代码

```python3
class Solution:
    def uniquePaths(self, m: int, n: int) -> int:
        child = 1
        mother = 1
        for i in range(m+n-2, n-1, -1):
            child *= i
        for i in range(1, m):
            mother *= i
        return int(child/mother)

```