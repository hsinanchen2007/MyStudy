【分析】Math
数学题，判断给定圆和矩形的位置关系(相离/相切/相交)，符合题意的情况为相切/相交。
（1）相离：4种情况；
（2）相切/相交：从圆的标准方程入手，对x∈[x_center-radius, x_center+radius]，求出y(可能有一解/两解，记为y1和y2, y2 <= y1)，然后判断此矩形中是否有点在(x, y2)和(x, y1)之间即可。
    时间复杂度O(n), 空间复杂度O(n)。
```
class Solution:
    def checkOverlap(self, radius: int, x_center: int, y_center: int, x1: int, y1: int, x2: int, y2: int) -> bool:
        # 相离
        if x_center + radius < x1 or x_center - radius > x2 or y_center + radius < y1 or y_center - radius > y2:
            return False
        # 枚举x∈[x_center-radius, x_center+radius], 求出此x下对应的圆上的点(x, y_pos2)和(x, y_pos1), y_pos2 <= y_pos1
        for x in range(x_center - radius, x_center + radius + 1):
            y_pos1 = math.sqrt(radius * radius - pow((x - x_center), 2)) + y_center
            if math.sqrt(radius * radius - pow((x - x_center), 2)) == 0:
                y_pos2 = y_pos1
            else:
                y_pos2 = y_center - abs(y_pos1 - y_center)
            # 相切/相交
        if (x1 <= x <= x2 and y1 <= y_pos1 <= y2) or (x1 <= x <= x2 and y1 <= y_pos2 <= y2) or (x1 <= x <= x2 and y_pos2 <= y1 <= y_pos1) or (x1 <= x <= x2 and y_pos2 <= y2 <= y_pos1):
                return True
        return False
```
