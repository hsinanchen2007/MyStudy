
```
class Solution:
    def calculateMinimumHP(self, dungeon: List[List[int]]) -> int:
        rows = len(dungeon)
        columns = len(dungeon[0])
        d = [[0] * columns for _ in range(rows)]
        d[-1][-1] = max(1, 1 - dungeon[-1][-1])#如果为正整数，则取1；否则取1-该数
        for i in range(columns-2, -1, -1):#初始化下边界
            d[-1][i] = max(d[-1][i+1] - dungeon[-1][i], 1)
        for i in range(rows-2, -1, -1):#初始化右边界
            d[i][-1] = max(d[i+1][-1] - dungeon[i][-1], 1)
        for x in range(rows-2, -1, -1):#其他取右边和下边的最小值用作计算
            for y in range(columns-2, -1, -1):
                d[x][y] = max(min(d[x+1][y], d[x][y+1]) - dungeon[x][y], 1)
        return d[0][0]
```
