'''可以理解为这是一个广度优先搜索
        正好使用一下堆栈的结构
        1.检测有多少腐烂，并放入一个存储结构类似，然后计数0
        2.然后对于存储器中的每个元素，判断邻居节点，如果是1那么就变成2
        3.如果存储器中已经没有元素，那么判断矩阵中是否有1，否则返回2

        '''
```python3
class Solution:
    def orangesRotting(self, grid: List[List[int]]) -> int:
        '''可以理解为这是一个广度优先搜索
        正好使用一下堆栈的结构
        1.检测有多少腐烂，并放入一个存储结构类似，然后计数0
        2.然后对于存储器中的每个元素，判断邻居节点，如果是1那么就变成2
        3.如果存储器中已经没有元素，那么判断矩阵中是否有1，否则返回2

        '''
        
        now=[]
        sum=0
        for i in range(len(grid)):
            for j in range(len(grid[i])):
                if grid[i][j]==2:
                    
                    now.append((i,j))
                if grid[i][j]==1 or grid[i][j]==2:
                    sum=sum+1
        if sum==0:
            return 0
        count=-1
        def neghbour_bad(now,i,grid):
            
            #print(grid,'li')
            if 0<=i[0]+1<len(grid):
                if  grid[i[0]+1][i[1]]==1:
                    grid[i[0]+1][i[1]]=2
                    now.append((i[0]+1,i[1]))
            if 0<=i[0]-1<len(grid):
                if  grid[i[0]-1][i[1]]==1:
                    grid[i[0]-1][i[1]]=2
                    now.append((i[0]-1,i[1]))
            if 0<=i[1]+1<len(grid[i[0]]):
                
                if  grid[i[0]][i[1]+1]==1:
                    grid[i[0]][i[1]+1]=2
                    now.append((i[0],i[1]+1))
            if 0<=i[1]-1<len(grid[i[0]]):
                if  grid[i[0]][i[1]-1]==1:
                    grid[i[0]][i[1]-1]=2
                    now.append((i[0],i[1]-1))
            

        while now:
            old=now
            count+=1
            now=[]
            for i in old:
                #print(old,i)
                neghbour_bad(now,i,grid)
                #print(grid,'wai')




            
        for i in range(len(grid)):
            for j in range(len(grid[i])):
                if grid[i][j]==1:
                    return -1
        return count
```
