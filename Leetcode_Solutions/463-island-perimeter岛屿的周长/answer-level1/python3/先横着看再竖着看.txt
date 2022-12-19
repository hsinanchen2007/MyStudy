### 解题思路
横竖是一样的，看一行有多少个block（连续的1），每一个block贡献两个周长，再看每一列

### 代码

```python3
class Solution:
    def islandPerimeter(self, grid: List[List[int]]) -> int:

        m, n = len(grid), len(grid[0])
        ans = 0

        for i in range(m):
            b_num = 0
            b_flag = 0
            for j in range(n):
                if grid[i][j] == 1:
                    if b_flag == 0:
                        b_num += 1
                        b_flag = 1
                else:
                    b_flag = 0
            ans += b_num * 2
        
        for j in range(n):
            b_num = 0
            b_flag = 0
            for i in range(m):
                if grid[i][j] == 1:
                    if b_flag == 0:
                        b_num += 1
                        b_flag = 1
                else:
                    b_flag = 0
            ans += b_num * 2

        return ans
```