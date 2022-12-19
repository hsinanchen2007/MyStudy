### 解题思路

分情况讨论，将矩形的边延长，可以将空间划分为九块，每一块分类就可以。

每一个区域可以看做圆的半径不断扩张，找到每个区域和矩形相交的临界情况，判断即可。

比如圆心在左上角，只需要判断圆心到左上角的距离和半径的关系即可。诸如此类

时间复杂度`o(1)`  空间复杂度`o(1)`

### 代码

```python3
class Solution:
    def checkOverlap(self, radius: int, x_center: int, y_center: int, x1: int, y1: int, x2: int, y2: int) -> bool:
        if x_center >= x1 and x_center <= x2 and y_center >= y1 and y_center <= y2:
            return True
        if  x_center < x1:
            if y_center > y2:
                return (x_center - x1) * (x_center - x1) + (y_center - y2) * (y_center - y2) <= radius * radius
            elif y_center > y1:
                return abs(x_center - x1) <= radius
            else:
                return (x_center - x1) * (x_center - x1) + (y_center - y1) * (y_center - y1) <= radius * radius
        elif x_center < x2:
            if y_center > y2:
                return abs(y_center - y2) <= radius
            elif y_center < y1:
                return abs(y_center - y1) <= radius
        else:
            if y_center > y2:
                return (x_center - x2) * (x_center - x2) + (y_center - y2) * (y_center - y2) <= radius * radius
            elif y_center > y1:
                return abs(x_center - x2)  <= radius
            else:
                return (x_center - x2) * (x_center - x2) + (y_center - y1) * (y_center - y1) <= radius * radius
        
```