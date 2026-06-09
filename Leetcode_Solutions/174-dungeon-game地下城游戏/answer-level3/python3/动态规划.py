```
class Solution:
    def calculateMinimumHP(self, dungeon: List[List[int]]) -> int:
        rows = len(dungeon)
        cols = len(dungeon[0])
        m = [1]*(cols)
        for i in range(rows-1, -1, -1):
            for j in range(cols-1, -1, -1):
                c = []
                if j+1<cols:
                    c.append(m[j+1])
                if i+1<rows:
                    c.append(m[j])
                if not c:
                    c = [1]
                m[j] = max(1, -1*dungeon[i][j]+min(c))
        return m[0]
```
解法二
```
class Solution:
    def calculateMinimumHP(self, dungeon: List[List[int]]) -> int:
        rows = len(dungeon)
        cols = len(dungeon[0])
        m = [float('inf')]*(cols)
        m[cols-1] = 1
        for i in range(rows-1, -1, -1):
            m[cols-1] = max(1, m[cols-1]-dungeon[i][cols-1])
            for j in range(cols-2, -1, -1):               
                m[j] = max(1, min(m[j], m[j+1]) - dungeon[i][j])
        return m[0]
```
解法三
```
class Solution:
    def calculateMinimumHP(self, dungeon: List[List[int]]) -> int:
        rows = len(dungeon)
        cols = len(dungeon[0])
        m = [float('inf')]*(cols+1)
        m[cols-1] = 1
        for i in range(rows-1, -1, -1):
            for j in range(cols-1, -1, -1):               
                m[j] = max(1, min(m[j], m[j+1]) - dungeon[i][j])
        return m[0]
```
