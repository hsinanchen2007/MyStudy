### 解题思路
先生成一个全1矩阵然后就开始模拟深度优先。。
注意考虑特殊情况 19在数位上远远小于20所以整个可以到达的领域是不连续的。
穷举任何可以到达的序列即可得到结果。
大概脑补了一下从0开始的应该是最大的区域。。
时间复杂度O(mn)

### 代码

```python3
class Solution:
    def movingCount(self, m: int, n: int, k: int) -> int:
        matrix=[[1 for j in range(n)]for i in range(m)]
        self.ans=0
        max_ans=0
        def dfs(i,j,k):
            
            if i <m and i>=0 and j<n and j>=0 and matrix[i][j]==1 and (i%10+i//10+j%10+j//10)<=k:
                matrix[i][j]=0
                self.ans+=1
                for dx,dy in [[-1,0],[0,-1],[1,0],[0,1]]:
                    dx=i+dx
                    dy=j+dy
                    dfs(dx,dy,k)
            return
        for i in range(m):
            for j in range(n):
               dfs(i,j,k)
               max_ans= max(self.ans,max_ans)
               self.ans=0
               
        return max_ans
```