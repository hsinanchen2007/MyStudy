### 解题思路
1. 首先遍历一遍,如果值为2就将其入队,如果值为1就将记录其中数值为1的个数cnt加1
2. 然后开始出队,出队并访问上下左右4个方向上的值,如果有值为1,就cnt-1,并使这个值为2,将坐标入队,遍历一遍队列上的元素就令感染次数的值res+1,直至队列为空就退出.
3. 最后如果cnt>0,表示有未感染的橘子,返回-1,否则返回res

### 代码
```python3
class Solution:
    def orangesRotting(self, grid: [[int]]) -> int:
        m=len(grid)
        n=len(grid[0])
        cnt=0#记录其中值为1的个数
        res=-1#记录传染的时间
        deque=[]#用于存储值为2的坐标的队列
        d=[[-1,0],[0,1],[1,0],[0,-1]]#定义寻找的4个方向

        def inarea(x,y):#定义在范围内的区域
            return 0<=x<=(m-1) and  0<=y<=(n-1)

        for i in range(m):#遍历行
            for j in range(n):#遍历列
                if grid[i][j]==2:
                    deque.append((i,j))
                if grid[i][j]==1:
                    cnt+=1
        # lens=len(deque)
        if cnt==0:#如果其中没有值为1的需要感染的橘子,就直接返回0,
            return 0
        while deque:
            res += 1
            lens = len(deque)
            for i in range(lens):
                topx,topy=deque.pop(0)
                for i in range(4):
                    newx=topx+d[i][0]
                    newy=topy+d[i][1]
                    if inarea(newx,newy):#新的坐标在范围内时
                        if grid[newx][newy]==1:#如果上下左右有值为1,就令cnt减1,并将这个值入队列,其值改为2
                            cnt-=1
                            deque.append((newx,newy))
                            grid[newx][newy]=2
        if cnt>0:
            return -1
        else:
            return res
```