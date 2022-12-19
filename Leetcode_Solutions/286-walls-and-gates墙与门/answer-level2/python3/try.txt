### 解题思路
在这题collections.deque其实没啥用
![2.png](https://pic.leetcode-cn.com/3747ee3fd5b3c7bd811a7280e5051c94988e3a2bad71bada21ed45b602bf7cca-2.png)

### 代码

```python3
from collections import deque
class Solution:
    def wallsAndGates(self, rooms: List[List[int]]) -> None:
        """
        Do not return anything, modify rooms in-place instead.
        """
        if not rooms:
            return []
        row = len(rooms)
        col = len(rooms[0])
        search = collections.deque()
        for i in range(row):
            for j in range(col):
                if rooms[i][j] == 0:
                    search.append((i,j))
                    
            
        
        #pop.left() 
        print(search)
        while len(search):
            a,b = search.popleft()
            if a-1 >=0 and rooms[a-1][b] ==2147483647:
                search.append((a-1,b))
                rooms[a-1][b] = rooms[a][b]+1
            if a+1 <row and rooms[a+1][b] ==2147483647:
                search.append((a+1,b))
                rooms[a+1][b] = rooms[a][b]+1
            if b -1>=0 and rooms[a][b-1] ==2147483647:
                search.append((a,b-1))
                rooms[a][b-1] = rooms[a][b]+1
            if b+1 <col and rooms[a][b+1] ==2147483647:
                search.append((a,b+1))
                rooms[a][b+1] =rooms[a][b]+1
            
        return rooms
```