### 解题思路
递归（回溯？）的方法，首先分析好设置终止条件，4种情况：
1、超出寻路边界
2、遇到障碍
3、命中终点
4、路过（计算可以路过的点数）
每次move（上下左右），判断当前点位置满足以上1、2、3哪一种，并在当前点放置障碍，当前点判断结束，解除障碍。网格复制到类节省内存。
由于要通过所有可以通过的点，所以需要对通过0的点计数，开始时候把计数hitnum当做类的私有节省内存。发现无法对不成立的路径hitnum清零，hitnum的属性应该归于对应的当前点，通过递归不断生成当前点的hitnum并累加，和生成一张新的动态表差不多。最后把所有路的命中加到一起，输出。

### 代码

```python3
class Solution:
    def __init__(self):
        self.grid = []
        self.count = 0
        self.zeronum = 0
        self.blocknum = 0
        self.row = 0
        self.col = 0
        self.length = 0
    def uniquePathsIII(self, grid: List[List[int]]) -> int:
        start_row , start_col , self.blocknum = find_start(grid)
        self.zeronum = len(grid) * len(grid[0]) - 2 - self.blocknum
        self.grid = grid
        self.row = len(self.grid)
        self.col = len(self.grid[0])
        self.grid[start_row][start_col] = -1
        hitnum = 0
        self.count = self.move(start_row-1,start_col,hitnum) + self.move(start_row,start_col-1,hitnum) + self.move(start_row+1,start_col,hitnum) + self.move(start_row,start_col+1,hitnum)
        return self.count
    def move(self,row_pos_now,col_pos_now,hitnum):
        #up end or left end or down end or right end (miss)
        if row_pos_now < 0 or col_pos_now < 0 or row_pos_now >= self.row or col_pos_now >= self.col:
            return 0
        #up end or left end or down end or right end (block)
        if self.grid[row_pos_now][col_pos_now] == -1:
            return 0
        #up end or left end or down end or right end (hit)
        if self.grid[row_pos_now][col_pos_now] == 2:
            if hitnum == self.zeronum:
                return 1
            else:
                return 0
        hitnum += 1
        #move
        self.grid[row_pos_now][col_pos_now] = -1
        length = self.move(row_pos_now-1,col_pos_now,hitnum) + self.move(row_pos_now,col_pos_now-1,hitnum) + self.move(row_pos_now+1,col_pos_now,hitnum) + self.move(row_pos_now,col_pos_now+1,hitnum)
        self.grid[row_pos_now][col_pos_now] = 0
        return length

def find_start(grid):
    row = len(grid)
    col = len(grid[0])
    blocknum = 0
    for i in range(row):
        for j in range(col):
            if grid[i][j] == 1:
                a = i
                b = j
            elif grid[i][j] == -1:
                blocknum +=1
    return a,b,blocknum
	
    
    
```