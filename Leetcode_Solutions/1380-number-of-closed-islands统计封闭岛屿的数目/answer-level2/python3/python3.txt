### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def closedIsland(self, grid: List[List[int]]) -> int:
        s = set()
        def find(i,j):
            if i<0 or j<0 or i>=len(grid) or j >=len(grid[0]):
                return False
            elif grid[i][j]==1:
                return True
            s.add((i,j))
            res = True
            if (i+1,j) not in s:
                res &= find(i+1,j)
            if (i-1,j) not in s:
                res&=find(i-1,j)
            if (i,j-1) not in s:
                res&=find(i,j-1)
            if (i,j+1) not in s:
                res&=find(i,j+1)
            return res
        ans = 0
        for i in range(len(grid)):
            for j in range(len(grid[0])):
                if grid[i][j]==0 and (i,j) not in s:
                    if find(i,j):
                        ans+=1
        return ans
```