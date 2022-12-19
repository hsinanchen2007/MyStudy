```
class Solution:
    def generateMatrix(self, n: int) -> List[List[int]]:
        result = [[0]*n for _ in range(n)]
        x, y, dx, dy = 0, 0, 0, 1
        for i in range(1, n**2+1):
            result[x][y] = i
            if result[(x+dx)%n][(y+dy)%n]:  # 这里理解判断条件是关键
                dx, dy = dy, -dx
            x += dx
            y += dy
        return result
                
```