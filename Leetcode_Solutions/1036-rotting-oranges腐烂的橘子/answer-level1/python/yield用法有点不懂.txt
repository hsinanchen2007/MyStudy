### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def orangesRotting(self, grid: List[List[int]]) -> int:
        queue=[]
        row=len(grid)
        cul=len(grid[0])

        for i in range(row):
            for j in range(cul):
                if grid[i][j]==2:
                    queue.append([i,j,0])
        #return queue
       
        def neigber(r,c):
             for [p,q] in [[r-1,c],[r+1,c],[r,c-1],[r,c+1]]:
                if 0<=p<row and 0<=q<cul:
                    yield p,q
        d=0        
        while queue:
            r,c,d=queue.pop(0)
            for p,q in neigber(r,c):
                if grid[p][q]==1:
                    grid[p][q]=2
                    queue.append([p,q,d+1])
                    
            
        
        for i in range(row):
            for j in range(cul):
                if grid[i][j]==1:
                    return -1
        return d


```