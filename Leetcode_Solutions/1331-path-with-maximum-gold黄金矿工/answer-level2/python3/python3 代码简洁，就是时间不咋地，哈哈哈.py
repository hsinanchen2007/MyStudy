### 解题思路
此处撰写解题思路
思路很快很清晰，但是时间不咋地，哈哈哈，先来说说思路吧
前面的代码都是固定的，包括四周的有效下标生成不再赘述

travel 函数当grid[i][j]不为0的时候才可以进入，进入travel，你加上了这个矿的黄金，就变为了0，之后也就不会再进入的，这是你的选择。
如果你不选择这个，你就的变回去原来的黄金数量，所以这里t记录原黄金数量，到最后的for循环结束变回去。

不太明白为啥运行这么慢，，，这位[道友](https://leetcode-cn.com/problems/path-with-maximum-gold/solution/dfsyou-hua-ban-by-erik_chen/)的优化版本的dfs可以推荐去关注
效率挺高的，，对比真是差距好大，哈哈哈
### 代码

```python3
class Solution:
    def getMaximumGold(self, grid: List[List[int]]) -> int:
        n,m = len(grid),len(grid[0])

        def neighbour(i,j):
            for r,c in ((i-1,j),(i+1,j),(i,j-1),(i,j+1)):
                if 0<=r<n and 0<=c<m:
                    yield r,c
        
        self.ans = 0
        def travel(i,j,res=0): # (i,j)不可以是0进入函数
            t = grid[i][j]
            res+=grid[i][j]
            grid[i][j] = 0

            for r,c in neighbour(i,j):
                if grid[r][c]!=0:
                    travel(r,c,res)
            grid[i][j] = t
            self.ans = max(res,self.ans)
        
        for i in range(n):
            for j in range(m):
                if grid[i][j]>0:
                    travel(i,j)
        return self.ans
```