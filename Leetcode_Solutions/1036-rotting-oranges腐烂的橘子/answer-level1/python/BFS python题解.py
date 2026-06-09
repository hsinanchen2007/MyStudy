### 解题思路
BFS广度遍历，我记得树结构的时候，广度遍历的思路就是用一个队列先进先出的特性，把孩子进去，然后依次pop，这些孩子在队列的优先度自然比不上它父亲的孩子，这样就实现了一层层的广度遍历，这题类似，但是我们很明显无法用队列，因为这样不好判断是否进入下一层，换而言之，我们无法计数时间，我想到冒泡排序中的当一个循环中，没有元素被交换的话，我们可以认为这个冒泡排序结束了，这里也可以用这个思想，我们用fulan这个列表来统计当前腐烂的水果，new_fulan来统计被当前腐烂的水果而腐烂的水果,当new_fulan为空的话，我们可以认为腐烂过程结束，然后其他过程可以借鉴广度遍历即可，

### 代码

```python
class Solution():
    def orangesRotting(self, grid):
        # 网格的长，宽
        m, n = len(grid), len(grid[0])
        fulan=[[i,j] for i in range(m) for j in range(n) if grid[i][j]==2]
        direction=[[-1,0],[1,0],[0,1],[0,-1]]
        #visit=[[0]*n for i in range(m)]
        minuter=0
        while True:
            new_fulan=[]
            while fulan:
                tmp=fulan.pop()
                for i in direction:
                    new_x,new_y=tmp[0]+i[0],tmp[1]+i[1]
                    if  -1<new_x<m and -1<new_y<n and grid[new_x][new_y]==1:
                        grid[new_x][new_y]=2
                     #   visit[new_x][new_y]=1
                        new_fulan.append([new_x,new_y])
            if not new_fulan:
                break
            fulan=new_fulan
            minuter+=1
        if [[i,j] for i in range(m) for j in range(n) if grid[i][j]==1]:
            return -1
        return minuter

```