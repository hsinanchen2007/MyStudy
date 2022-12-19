### 解题思路
开一个和grid相同大小的格子spread记录每个位置腐烂的时间点，那么题目的答案就是这些位置中最大的时间点。
考虑到腐烂是从相邻位置扩散的，那么每个格子扩散的时间=min（相邻格子腐烂的时间）+1
初始腐烂的橘子腐烂的时间为0，将初始没有橘子的地方（0）和有新鲜橘子的地方（1）的时间设置为inf，这样被0包围的1的腐烂时间永远是inf。
更新腐烂时间是一个循环，当一轮更新下来，所有橘子的腐烂时间都没有变化，那么循环需要结束。
注意：数组的中间、边、角的周围格子数不一样，需要单独处理，所有代码非常麻烦。

### 代码

```python3
class Solution:
    def orangesRotting(self, grid: List[List[int]]) -> int:
        if not grid:return 0
        #每个2向外扩散，在spread里记录每个格子被感染的最短路径,每次每个grid里为1的格子都更新为周围最小的值+1
        rots=[]
        m,n=len(grid),len(grid[0])
        spread=[[0]*n for i in range(m)]
        has_fresh=False
        for i in range(m):
            for j in range(n):
                if grid[i][j]==2:
                    rots.append([i,j])
                    spread[i][j]=0
                elif grid[i][j]==1:
                    spread[i][j]=float('inf')
                    has_fresh=True
                else:
                    spread[i][j]=float('inf')
        #print(spread,rots)
        if not rots:
            if has_fresh:#无2有1
                return -1
            else:#无2无1
                return 0
        changed=True
        while changed:
            changed=False
            if m>1 and n>1:
                for i in range(m):
                    for j in range(n):
                        if grid[i][j]==1:
                            start=spread[i][j]
                            if i==0 and j==0:
                                spread[i][j]=min(spread[i+1][j],spread[i][j+1])+1
                            elif i==0 and 1<=j<=n-2:
                                spread[i][j]=min(spread[i+1][j],spread[i][j+1],spread[i][j-1])+1
                            elif i==0 and j==n-1:
                                spread[i][j]=min(spread[i+1][j],spread[i][j-1])+1
                            elif i==m-1 and j==0:
                                spread[i][j]=min(spread[i-1][j],spread[i][j+1])+1
                            elif i==m-1 and 1<=j<=n-2:
                                spread[i][j]=min(spread[i-1][j],spread[i][j+1],spread[i][j-1])+1
                            elif i==m-1 and j==n-1:
                                spread[i][j]=min(spread[i-1][j],spread[i][j-1])+1
                            elif 1<=i<=m-2 and j==0:
                                spread[i][j]=min(spread[i-1][j],spread[i+1][j],spread[i][j+1])+1
                            elif 1<=i<=m-2 and j==n-1:
                                spread[i][j]=min(spread[i-1][j],spread[i+1][j],spread[i][j-1])+1
                            elif 1<=i<=m-2 and 1<=j<=n-2:
                                spread[i][j]=min(spread[i-1][j],spread[i+1][j],spread[i][j+1],spread[i][j-1])+1
                            if start!=spread[i][j]:
                                changed=True
                                #print(spread)
            elif m>1 and n==1:
                for i in range(m):
                    start=spread[i][j]
                    if grid[i][j]==1:
                        if i==0:
                            spread[i][j]=spread[i+1][j]+1
                        elif i<=m-2:
                            spread[i][j]=min(spread[i-1][j],spread[i+1][j])+1
                        else:
                            spread[i][j]=spread[i-1][j]+1
                    if start!=spread[i][j]:
                        changed=True
            elif m==1 and n>1:
                for j in range(n):
                    start=spread[i][j]
                    if grid[i][j]==1:
                        if j==0:
                            spread[i][j]=spread[i][j+1]+1
                        elif j<=n-2:
                            spread[i][j]=min(spread[i][j-1],spread[i][j+1])+1
                        else:
                            spread[i][j]=spread[i][j-1]+1
                    if start!=spread[i][j]:
                        changed=True
        #print('end',spread)
        mint=0
        for i in range(m):
            for j in range(n):
                if grid[i][j]==1:
                    mint=max(spread[i][j],mint)
        if mint==float('inf'):
            return -1
        else:
            return mint
                        



```