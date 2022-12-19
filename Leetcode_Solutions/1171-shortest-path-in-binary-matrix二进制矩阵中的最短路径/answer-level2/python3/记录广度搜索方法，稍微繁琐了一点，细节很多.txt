### 解题思路
广度遍历方法，每遍历一次，长度加1，并且要把之前遍历过的值做好标记。
每次遍历集合，取第一个值搜索，如果符合条件，加进来时，python要插入到前面，否则每次访问都是最新加入的。

### 代码

```python3
class Solution:
    def shortestPathBinaryMatrix(self, grid: List[List[int]]) -> int:
        directions = [[-1,1],[-1,0],[-1,-1],[0,-1],[1,-1],[1,0],[1,1],[0,1]]
        pointN = len(grid)
        list1 = [[0,0]]
        length = 0
        if grid[0][0]==1:
            return -1
        if grid[0][0]==0 and len(grid[0])==1:
            return 1
        while len(list1)!=0:
            length += 1
            size = len(list1)
            while size > 0:
                list_1 = list1[-1]
                del list1[-1]
                grid[list_1[0]][list_1[1]] = 1
                for value in directions:
                     xc = list_1[0]+value[0]
                     yc = list_1[1]+value[1]
                     if xc<0 or xc >=pointN or yc <0 or yc>=pointN or grid[xc][yc]==1:
                        continue
                     if xc == pointN-1 and yc == pointN-1:
                        return length+1
                     else:
                        grid[xc][yc] = 1
                        if len(list1)==0:
                            list1.append([xc,yc])
                        else:
                            list1.insert(0,[xc,yc])
                size = size -1

        return -1
                
                    
```