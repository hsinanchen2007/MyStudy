### 解题思路
第一次用Python
看了官方题解+甜姨的图，差不多明白了。Python语言真是简洁~~
### 代码

```python
class Solution(object):
    def surfaceArea(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        N = len(grid)
        ans = 0
        for r in xrange(N):  #xrange()返回一个生成器，而不是数组
            for c in xrange(N):
                if grid[r][c]:
                    ans+=2
                    for nr,nc in ((r-1,c),(r+1,c),(r,c-1),(r,c+1)):  # 遍历四个方向
                        if 0<=nr<N and 0<=nc<N:
                            nval=grid[nr][nc]  # 旁边正方体的高度
                        else:
                            nval=0
                        ans+=max(grid[r][c]-nval,0)
        return ans

```