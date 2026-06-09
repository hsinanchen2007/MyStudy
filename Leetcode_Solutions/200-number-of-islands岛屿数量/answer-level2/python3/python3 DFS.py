### 解题思路
看到好多人找到1之后把整个岛变成了0
丧心病狂呀！！！
1本来就少了还搞成0，这不是差距更大了吗？
还是搞成-1会好一点


### 代码

```python3
class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        if len(grid)==0:
            return 0
        lenght=len(grid)
        width=len(grid[0])
        def change_color(x,y):
            grid[x][y]="-1"
            if x>0 and grid[x-1][y]=="1":
                change_color(x-1,y)
            if y>0 and grid[x][y-1]=="1":
                change_color(x,y-1)
            if x<lenght-1 and grid[x+1][y]=="1":
                change_color(x+1,y)
            if y<width-1 and grid[x][y+1]=="1":
                change_color(x,y+1)
        count=0
        for x in range(lenght):
            for y in range(width):
                if grid[x][y]=="1":
                    count+=1
                    change_color(x,y)
                    
        return count
```