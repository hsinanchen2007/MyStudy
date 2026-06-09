看到很多用乘法做的，虽然能通过，但是存在一个bug，如果三点成水平和垂直的直角（L型），那么乘法是会出错的。用除法，存在除以0的问题，这里我们让除以0变成无穷大就可以了。

```
class Solution:
    def checkStraightLine(self, coordinates: List[List[int]]) -> bool:
        n = len(coordinates)
        if n == 2: return True
        try: slope = (coordinates[1][1] - coordinates[0][1]) / (coordinates[1][0] - coordinates[0][0])
        except: slope = float('inf')
        for i in range(3, n):
            try: cur = (coordinates[i][1] - coordinates[i-1][1]) / (coordinates[i][0] - coordinates[i-1][0])
            except: cur = float('inf')
            if cur != slope: return False
        return True
```
