
python3 EZ
`dist`是Python 3.8新加到math库的函数，可以计算两点之间距离（空间也可以，更高也可以）
```python []
class Solution:
    def checkOverlap(self, radius: int, x_center: int, y_center: int, x1: int, y1: int, x2: int, y2: int) -> bool:
        a = max(0, x1 - x_center, x_center - x2) ** 2 
        b = max(0, y1 - y_center, y_center - y2) ** 2
        c = radius ** 2
        return a + b <= c
```
```python []
class Solution:
    def checkOverlap(self, radius: int, x_center: int, y_center: int, x1: int, y1: int, x2: int, y2: int) -> bool:
        for x in (x1, x2):
            for y in (y1, y2):
                if dist((x_center, y_center), (x, y)) <= radius:
                    return True
        if x1 <= x_center <= x2 and y1 - radius  <= y_center <= y2 + radius:
            return True
        if x1 - radius <= x_center <= x2 + radius and y1  <= y_center <= y2:
            return True
        return False
```
一行版本
```python []
return max(0, x1 - x_center, x_center - x2) ** 2 + max(0, y1 - y_center, y_center - y2) ** 2 <= radius ** 2
```
```python []
return x1 <= x_center <= x2 and y1 - radius <= y_center <= y2 + radius or x1 - radius <= x_center <= x2 + radius and y1  <= y_center <= y2 or any(dist((x_center, y_center), (x, y)) <= radius for x in (x1, x2) for y in (y1, y2))
```