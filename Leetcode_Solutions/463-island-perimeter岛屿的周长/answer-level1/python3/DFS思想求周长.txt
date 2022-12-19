刚刚从695题岛屿最大面积那里跑过来，再练练DFS思想。


```
class Solution:
    def islandPerimeter(self, grid: List[List[int]]) -> int:
        row=len(grid)
        line=len(grid[0])
        res=0 #记录周长
        
        for i in range(row):
            for j in range(line): #遍历整个表格
                if grid[i][j]==1: #当为陆地时
                    for di,dj in [[0,1],[1,0],[0,-1],[-1,0]]: #判断右上下左
                        cur_i=i+di
                        cur_j=j+dj
                        if cur_i<0 or cur_i>=row or cur_j<0 or cur_j>=line or grid[cur_i][cur_j]==0:
#若为边界以外的或者旁边为海水的话，那么边长加一
                            res+=1
                            
                            
        return res
        
```
![43CE40E2-F40E-45E9-8423-4794308CEE73.png](https://pic.leetcode-cn.com/45cb15a786ee0d006043dcbc7fc25391a8a1c264298eb407f4527c6ce67fe938-43CE40E2-F40E-45E9-8423-4794308CEE73.png)

学习学习思想，但可以看到这个题时空效率很低了.......