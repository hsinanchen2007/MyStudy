核心思想：一句话：判断障碍不在路上，且目标在路上。 那么可以复用判断函数on_the_way.

优化思路：以一次指令循环为一个平移区域或者单位，不断向右上叠加。叠加到最后一次接近目标区域后：

    1，看下目标或者障碍是不是远离指令区域。远离那就说明结果是否
    2，否则，就要经过一次循环进行判断了。

很简单，但有几个坑。看注释~

```python
class Solution:
    def __init__(self):
        self.unit_x = 0;
        self.unit_y = 0;

    def init_unit(self, command):
        for c in command:
            if c == 'R':
                self.unit_x += 1;
            else:
                self.unit_y += 1;

    def get_floor_xy(self, x, y):
        if (self.unit_x == 0):
            return 0, y - (y % self.unit_y)
        elif (self.unit_y == 0):
            return x - (x % self.unit_x), 0
        min_count = min(int(x / self.unit_x), int(y / self.unit_y))
        return min_count * self.unit_x, min_count * self.unit_y
    
    def on_the_way(self, command, x1, y1):
        # 以一次循环为单位，历经多个循环后，找到最接近目标的坐标。
        x0, y0 = self.get_floor_xy(x1,y1)
        # 最接近的目标就是目标，直接返回。
        if x0 == x1 and y0 == y1:
            return True
        # 判断单次循环下，目标x1,y1是否超出范围unit_x, unit_y圈定的区域。
        if (x1 - x0) > self.unit_x:
            return False
        if (y1 - y0) > self.unit_y:
            return False
        # 目标在圈定范围内，单次循环下依次判定，目标是否在路上。
        for c in command:
            if c == 'R':
                x0 += 1;
            else:
                y0 += 1;
            if x0 == x1 and y0 == y1:
                return True
        return False
        
    def robot(self, command: str, obstacles: List[List[int]], x: int, y: int) -> bool:
        self.init_unit(command)
        # 终点是在路上，还是在路两侧。不在路上，趁早反馈。
        if not self.on_the_way(command, x, y):
            return False
        # 依次确认障碍点是否在路上
        for obs in obstacles:
            # 障碍点是不是超出了终点范围，超出了就没意义了。
            if obs[0] >= x or obs[1] >= y:
                continue
            # 障碍点在路上说明不可达。
            if self.on_the_way(command, obs[0], obs[1]):
                return False
        return True
```
