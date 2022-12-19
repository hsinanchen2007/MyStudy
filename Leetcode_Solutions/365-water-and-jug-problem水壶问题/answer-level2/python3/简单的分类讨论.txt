* 算法：我们把倒水的流程切成一小段的`单元`，每个`单元`倒若干次水。通过这样的格式化，每个单元只有两种情况。
    * 设`x < y`，把`y壶有水，x壶无水`作为`每个单元`的初始情况。设y壶的水量为`t`。`res`存储y壶的可能水量。
    * 如果`t > x`，执行以下步骤：1.把y壶倒入x壶中，直到x壶满，2.把x壶的水倒空。此时又回到`y壶有水，x壶无水`的初始情况，`y`中的水量为`t-x`，作为新单元的起始。在这个倒水的过程中，如果`z == t`，就可以返回`True`。
    * 如果`t <= x`，执行以下步骤：1. 把y壶的`t`全倒入`x`，2.把`y`倒满，3.把`y`倒入`x`直到`x`满，4.把`x`倒空。此时又回到`y壶有水，x壶无水`的初始情况，`y`中的水量为`y-x+t`，作为新单元的起始。在这个倒水的过程中，如果`z == t`或者`z == t + y`，都可以返回`True`

* note：首先把特殊情况排除掉；用hashset来存储而不是list。

### 代码
```python []
class Solution:
    def canMeasureWater(self, x: int, y: int, z: int) -> bool:
        
        if z == 0:
            return True
        if z > x + y:
            return False

        res = set()
        if x > y:
            x, y = y, x

        t = y
        while not t in res:
            res.add(t)
            if t > x:
                t = t - x
            else:
                t = y - x + t
            if z == t or z == t + x:
                return True
        return False
```