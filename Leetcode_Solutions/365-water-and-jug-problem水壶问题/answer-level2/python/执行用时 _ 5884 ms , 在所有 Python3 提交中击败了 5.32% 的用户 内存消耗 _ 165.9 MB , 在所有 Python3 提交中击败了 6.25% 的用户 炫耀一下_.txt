### 解题思路
深度优先搜索，6种操作只能进行一次，若6种都执行完毕后仍不满足，就输出False

### 代码

```python3
class Solution:
    def canMeasureWater(self, x: int, y: int, z: int) -> bool:
        remain = [(0,0)]
        #防止进入无限循环
        pool = set()
        while remain:
            remain_x, remain_y = remain.pop()
            if remain_x == z or remain_y == z or remain_x + remain_y == z:
                return True
            if (remain_x, remain_y) in pool:
                continue
            pool.add((remain_x,remain_y))
            #将X壶倒满
            remain.append((x, remain_y))
            #将Y壶倒满
            remain.append((remain_x, y))
            #将X壶倒空
            remain.append((0, remain_y))
            #将Y壶倒空
            remain.append((remain_x, 0))
            #将X壶的水倒入Y壶至倒满
            remain.append((remain_x- min(remain_x, y-remain_y), remain_y + min(remain_x, y-remain_y)))
            #将Y壶的水导入X壶至倒满
            remain.append((remain_x + min(remain_y, x-remain_x), remain_y- min(remain_y, x-remain_x)))
        return False 
```