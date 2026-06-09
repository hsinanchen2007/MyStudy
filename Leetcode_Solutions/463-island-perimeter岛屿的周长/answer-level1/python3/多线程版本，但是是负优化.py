### 解题思路
此处撰写解题思路

### 代码

```python3
import queue
import threading
class Solution:
    
    def islandPerimeter(self, grid: List[List[int]]) -> int:
        def useable(grid,t1_result):
            count_useable = 0
            count_useable=0
            for i in grid:
                for m in i:
                    if(m==1):
                        count_useable=count_useable+1
            t1_result.put(count_useable)

        def count_row(grid,t2_result):
            lenth = len(grid[0])
            count_row=0
            for i in grid:
                for m in range(lenth-1):
                    z=m+1
                    if(i[m]==1 and i[m]==i[z]):
                        count_row=count_row+1
            t2_result.put(count_row)

        def count_col(grid,t3_result):
            lenth = len(grid[0])
            width = len(grid)
            count_col = 0
            for i in range(lenth):
                for m in range(width - 1):
                    z = m + 1
                    if (grid[m][i] == 1 and grid[z][i] == grid[m][i]):
                        count_col = count_col + 1
            t3_result.put(count_col)

        q=queue.Queue()
        t1_result=0
        t2_result=0
        t3_result=0
        t1=threading.Thread(target=useable,args=(grid,q))
        t2=threading.Thread(target=count_col,args=(grid,q))
        t3=threading.Thread(target=count_row,args=(grid,q))
        t1.start()
        t2.start()
        t3.start()
        t1.join()
        print("t1 done")
        t2.join()
        t3.join()
        result=[]
        for i in range(3):
            result.append(q.get())
        zhi=result[0]*4-2*(result[1]+result[2])
        return zhi
```