## 解题思路

从左下角第一个元素开始，每一次循环先向右扫描，找到第一个负数，然后向上扫描，找到第一个非负数，
那么这个点左边都是非负的，右下角都是负数

然后在从这个点开始继续上面的循环即可

## 代码

```python
class Solution:
    def countNegatives(self, grid: List[List[int]]) -> int:
        m = len(grid)
        n = len(grid[0])
        i = m - 1
        j = 0
        a = m
        b = n
        result = 0
        while i >= 0 and j <= n - 1:
            while j <= n-1 and grid[i][j] >= 0:
                j += 1
            while i >= 0 and j <= n-1 and grid[i][j] < 0:
                i -= 1
            result += (a-i-1) * (b - j)
            a = i+1
        return result
```