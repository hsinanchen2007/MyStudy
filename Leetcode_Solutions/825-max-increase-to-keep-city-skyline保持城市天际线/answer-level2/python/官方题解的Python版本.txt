### 解题思路

做题的时候和官方思路是一样的，所以就不赘述了
[官方题解](https://leetcode-cn.com/problems/max-increase-to-keep-city-skyline/solution/bao-chi-cheng-shi-tian-ji-xian-by-leetcode/)


### 代码

```python3
class Solution:
    def maxIncreaseKeepingSkyline(self, grid: List[List[int]]) -> int:
        max_i = []
        max_j = []
        res = 0
        for a in grid:
            max_i.append(max(a))
        for i in range(len(grid[0])):
            max_j.append(max(grid, key = lambda k: k[i])[i])
        
        for i in range(len(grid)):
            for j in range(len(grid[0])):
                res += min(max_i[i], max_j[j]) - grid[i][j]
        return res
```