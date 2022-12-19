### 解题思路
1.由于递归层数太多 用stack构造
2.ax+by=z 有整数解，当x,y的最大公约数可以被z整除
### 代码

```python3
class Solution:
    def canMeasureWater(self, x: int, y: int, z: int) -> bool:
        # stack = [(0, 0)]
        # seen = set()
        # while stack:
        #     x_remain, y_remain = stack.pop()
        #     if x_remain+y_remain == z:
        #         return True
        #     if (x_remain, y_remain) in seen:
        #         continue
        #     seen.add((x_remain, y_remain))
        #     stack.append((0, y_remain))
        #     stack.append((x_remain, 0))
        #     stack.append((x, y_remain))
        #     stack.append((x_remain, y))
        #     stack.append((x_remain-min(x_remain, y-y_remain), 
        #                 y_remain+min(x_remain,y-y_remain)))
        #     stack.append((x_remain+min(x-x_remain, y_remain),
        #                 y_remain-min(x-x_remain, y_remain)))
        # return False
        if x+y<z: return False
        if z == 0: return True
        if x==0 and y==0: return False
        if x==0 or y==0: return z==x or z==y
        return z% math.gcd(x,y) == 0
            
```