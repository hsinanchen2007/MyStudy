### 解题思路
直接记录每步可能出现的杯中的水量情况，对于已经出现过的，则不再搜索。
开始seeked用的列表，发现超时..只好改用set
leetcode对于时间还是卡挺死的

### 代码

```python3
class Solution:
    def canMeasureWater(self, x: int, y: int, z: int) -> bool:
        if x==z or y==z or x+y==z:
            return True
        if x+y<z:
            return False
        
        stack = [(0,0)]
        seeked = set()
        
        while stack:
            (x_part, y_part) = stack.pop()
            if x_part==z or y_part==z or x_part+y_part==z:
                return True
            if (x_part, y_part) not in seeked: # 记录这个剩水情况是否出现过
                seeked.add((x_part, y_part))
                # 以此为基础倒水，可能出现的情况为:
                # 直接倒满x
                next0 = (x, y_part)
                stack.append(next0)
                # 直接倒空x
                next1 = (0, y_part)
                stack.append(next1)
                # 从x倒满y:可能出现（x剩，y满），或者（x空，y满），或者（x空，y部分）
                if x_part+y_part>y:
                    next2 = (x_part+y_part-y, y)
                else:
                    next2 = (0, x_part+y_part)
                stack.append(next2)
                # 从y倒满x
                if x_part+y_part>x:
                    next3 = (x, y_part+x_part-x)
                else:
                    next3 = (x_part+y_part, 0)
                stack.append(next3)
                # 倒满y
                next4 = (x_part, y)
                if next4 not in seeked:
                    stack.append(next4)
                # 倒空y
                next5 = (x_part, 0)
                stack.append(next5)
        
        return False       
```