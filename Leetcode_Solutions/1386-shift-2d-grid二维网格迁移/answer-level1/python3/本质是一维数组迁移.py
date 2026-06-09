借助一维数组展开二维数组数据，再按照一维数组平移得到移动后的值，更新二维数组结果
时间复杂度O(N)
空间复杂度O(N)

```python []
class Solution:
    def shiftGrid(self, grid: List[List[int]], k: int) -> List[List[int]]:
        if k==0:
            return grid
        m=len(grid)
        n=len(grid[0])
        trow=[]
        for row in grid:
            trow+=row
        tk=len(trow)
        k=k%tk
        nrow=trow[tk-k:tk]+trow[0:tk-k]
        for i in range(m):
            for j in range(n):
                grid[i][j]=nrow[i*n+j]
        return grid
```


