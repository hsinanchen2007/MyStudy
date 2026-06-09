### 解题思路
广度遍历，之前没有接触过这样类型的广度遍历，值得思考
self.seen如果使用list会超过时间限制。
注意结束条件

### 代码

```python3
class Solution:
    def canMeasureWater(self, x: int, y: int, z: int) -> bool:
        xx = 0
        yy = 0
        self.states = [(xx, yy)]
        self.seen = set()
        while self.states:
            xx , yy= self.states.pop()
            if xx==z or yy == z or xx + yy == z:
                return True 
            if (xx, yy) in self.seen:
                continue
            self.seen.add((xx, yy))
            # xx 灌满水
            self.states.append((x, yy))
            # xx 水倒光
            self.states.append((0, yy))
            # xx 水倒入yy,判断xx能否倒空，或者yy灌满
            if xx+yy > y:
                self.states.append((xx+yy - y, y))
            else:
                self.states.append((0, xx+yy))
            # yy 灌满水
            self.states.append((xx, y))
            # yy 水倒光
            self.states.append((xx, 0))
            # yy 水倒入xx，判断yy能否倒空，或者xx灌满
            if xx+yy > x:
                self.states.append((x, xx+yy - x))
            else:
                self.states.append((xx+yy, 0))
        return False
    
```