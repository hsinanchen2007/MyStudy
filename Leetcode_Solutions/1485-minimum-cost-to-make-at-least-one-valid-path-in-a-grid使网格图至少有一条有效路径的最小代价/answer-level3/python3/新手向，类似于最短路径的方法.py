从已经直到的起点开始，对于每个节点着色，从0开始着色。
因为比较新手所以可能写的比较啰嗦。
把不用更改就能够到达的节点都为0，然后寻找所有标注为0的节点，还没有标注的邻居节点为1
然后找到所有1能够达到的点，然后标注为1，然后再去寻找，和已经标注为1的节点的邻居中还没有标注的节点，标注为2，依次类推。
直到[-1][-1]已经被标注，就退出
```python3
class Solution:
    def minCost(self, grid: List[List[int]]) -> int:
        '''对这个格子着色，找到属于不同种类的群'''
        def new(x,y,lst,grid,num_now,lst_now):
            
            if grid[y][x]==1:
                x=x+1
            elif grid[y][x]==2:
                x=x-1
            elif grid[y][x]==3:
                y=y+1
            elif grid[y][x]==4:
                y=y-1
            
            if x<0 or x>=len(grid[0])or y<0 or y>=len(grid) :
                
                return 
            elif  lst[y][x]!=None:
                return
            else:
                lst[y][x]=num_now
                lst_now.append([x,y])
                
                new(x,y,lst,grid,num_now,lst_now)
        def find_next(lst_now,lst,num_now):
            lst_next=[]
            
            for i in lst_now:
                x=i[0]+1
                y=i[1]
                if x<0 or x>=len(grid[0])or y<0 or y>=len(grid):
                    pass
                elif  lst[y][x]!=None:
                    pass
                else:
                    lst[y][x]=num_now+1
                    lst_next.append([x,y])
                x=i[0]-1
                y=i[1]
                if x<0 or x>=len(grid[0])or y<0 or y>=len(grid):
                    pass
                elif  lst[y][x]!=None:
                    pass
                else:
                    lst[y][x]=num_now+1
                    lst_next.append([x,y])
                x=i[0]
                y=i[1]+1
                if x<0 or x>=len(grid[0])or y<0 or y>=len(grid):
                    pass
                elif  lst[y][x]!=None:
                    pass
                else:
                    lst[y][x]=num_now+1
                    lst_next.append([x,y])
                x=i[0]
                y=i[1]-1
                if x<0 or x>=len(grid[0])or y<0 or y>=len(grid):
                    pass
                elif  lst[y][x]!=None:
                    pass
                else:
                    lst[y][x]=num_now+1
                    lst_next.append([x,y])
            return lst_next    
            
        lst=[[None]*len(grid[0]) for _ in range(len(grid))]
        lst[0][0]=0
        lst_now=[[0,0]]
        lst_next=[]
        num_now=0
        
        while lst[-1][-1]==None:
            lst_start=lst_now
            for i in lst_start:
                new(i[0],i[1],lst,grid,num_now,lst_now)
            
            lst_next=find_next(lst_now,lst,num_now)
            num_now+=1
            lst_now=lst_next
        
        return lst[-1][-1]
```
