### 解题思路
此处撰写解题思路
不知道什么DFS，用了类似BFS的写法
### 代码

```python3
class Solution:
    def maxAreaOfIsland(self, grid: List[List[int]]) -> int:
        res,len1 ,len2 ,i  = 0,len(grid),len(grid[0]),0
        while sum([sum(g) for g in grid])>0:
            while sum(grid[i])==0:
                i+=1
            j= grid[i].index(1)
            point,tmp,grid[i][j]=[(i,j)],0,0
            while point:
                p_i,p_j=point.pop(0)
                for di,dj in [(-1,0),(1,0),(0,1),(0,-1)]:
                    if -1<p_i+di<len1 and -1<p_j+dj<len2 and grid[p_i+di][p_j+dj]==1 :
                        point.append((p_i+di,p_j+dj))
                        grid[p_i+di][p_j+dj]=0
                tmp+=1
            res = max(res,tmp)
        return res
```