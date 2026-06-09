主要得想明白xy是独立的，然后利用多项绝对值求和，具体题目具体分析，跳出bfs的圈子
```
class Solution:
    def minTotalDistance(self, grid: List[List[int]]) -> int:
        row=[]
        col=[]
        for i in range(len(grid)):
            for j in range(len(grid[0])):
                if grid[i][j]==1:
                    row.append(i)
                    col.append(j)
        row.sort()
        col.sort()
        res=0
        start,end=0,len(row)-1
        while start<end:
            res+=row[end]-row[start]+col[end]-col[start]
            start+=1
            end-=1
        return res
```
